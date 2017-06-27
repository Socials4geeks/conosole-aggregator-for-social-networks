#include "core.h"
#include "storages.h"
#include "types.h"
#include "exceptions.h"
#include "auth_by_login_password.h"

#include <utility>

Core::Core() {
    wasLoadedUsers = false;
    storage = new File();
    size_t sizeOfLoadedUsers;
    std::vector< authInfo > loadedUsers;
    char* ptr = (char *)&loadedUsers;
    storage->Get( "LocalLoginsPasswords", ptr, sizeOfLoadedUsers );  // TODO:Use serializator
    authorizator = new AuthorizatorByLoginPassword( loadedUsers );
};

Core::~Core() {
    size_t sizeOfLoadedOldUsers;
    std::vector< authInfo > loadedOldUsers;
    
    char* ptr = (char *)&loadedOldUsers;
    if ( storage->Get( "LocalLoginsPasswords", ptr, sizeOfLoadedOldUsers ) == OK ) {  // TODO:Use serializator
        wasLoadedUsers = true;
    }
    std::vector< authInfo > gotNewUsers = authorizator->GetUsers();  // TODO: Save new users
    if( !wasLoadedUsers || ( gotNewUsers != loadedOldUsers ) ){ //TODO Save Users with serializator
//        storage->Set( "LocalLoginsPasswords", gotNewUsers, gotNewUsers.size() * sizeof( gotNewUsers[0] ) );
    }
    delete authorizator;
    delete storage;
};

Response Core::ExecuteRequest( Request request  ) {
    Response response;
    response.Type = ERROR;
    params tmp;
    tmp.insert( std::make_pair( "SOCIAL_NETWORK_NAME", request.Params[ "SOCIAL_NETWORK_NAME" ] ) );
    response.Params.push_back( tmp );
    switch ( request.Action ) {
        case NEW_LOCAL_ACCOUNT: {
            if( request.Params.find( "LOCAL_USERNAME" ) == request.Params.end() ||
               request.Params.find( "LOCAL_PASSWORD" ) == request.Params.end()  ) {
                return response;
            }
            if( authorizator->Signup( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] ) != OK ) {
                return response;
            }
            response.Type = ACCEPT;
            break;
        }
        case LOGIN_LOCAL_ACCOUNT: {
            try {
                activeSession = authorizator->Login( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] );
                response.Type = ACCEPT;
            } catch ( BadAuth ) {}
            break;
        }
        case LOGOUT_LOCAL_ACCOUNT: {
            activeSession = Session();
            response.Type = ACCEPT; //TODO: Предусмотреть другие варианты
            break;
        }
        case SHOW_MESSAGES:
        case SHOW_WALL:
        case SHOW_FRIENDS:
        case SEND_MESSAGE:
        case ADD_WALL:
        case ADD_FRIEND:
        case REMOVE_FRIEND: {
            authInfo tmp = activeSession.GetAuthForApi( request.Params[ "SOCIAL_NETWORK_NAME" ] ); //Handle exception NoAuthData
            request.Params[ "REMOTE_LOGIN" ] = tmp.first;
            request.Params[ "REMOTE_PASSWORD" ] = tmp.second;
            response = implementer.ExecuteRequest( request );
            break;
        }
    }
    return response;
}

Status Core::RemoveSession( Session session ) {
    if ( !IsSessionActive( session ) ) {
        throw NotAuthorized();
        return UNKNOWN_ERROR;
    }
    for ( auto i : sessions ) {
        if( i == session ) {
            // TODO Delete Session
        }
    }
    return OK;
}

bool Core::IsSessionActive( Session session ) {
    for ( auto i : sessions ) {
        if( i == session ){
            return true;
        }
    }
    return false;
}

