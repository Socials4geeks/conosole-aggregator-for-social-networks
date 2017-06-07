#include "core.h"
#include "storages.h"
#include "types.h"
#include "exceptions.h"
#include "auth_by_login_password.h"

Core::Core() {
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
    storage->Get( "LocalLoginsPasswords", ptr, sizeOfLoadedOldUsers );  // TODO:Use serializator
//    std::vector< authInfo > gotNewUsers = authorizator->GotUsers();  // TODO: Save new users
/*    if( gotNewUsers != loadedOldUsers ){
        storage->Set( "LocalLoginsPasswords", gotNewUsers, gotNewUsers.size() * sizeof( gotNewUsers[0] ) );  // TODO:Use serializator
    } */
    delete authorizator;
    delete storage;
};

Response Core::ExecuteRequest( Request request  ) {
    Response response;
    response.Type = ERROR;
    switch ( request.Action ) {
        case NEW_LOCAL_ACCOUNT: {
            authorizator->Signup( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] );
            break; //Return response
        }
        case LOGIN_LOCAL_ACCOUNT: {
            activeSession = authorizator->Login( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] );
            break; //Return response
        }
        case LOGOUT_LOCAL_ACCOUNT: {
            activeSession = Session();
            break; //Return response
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
            return response;
            break;
        }
        default: {
            return response;
            break;
        }
    }
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

