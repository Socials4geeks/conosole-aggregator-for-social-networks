#include "core.h"
#include "file.h"
#include "types.h"
#include "auth_by_login_password.h"

Core::Core() {
    size_t sizeOfLoadedUsers;
    std::vector< authInfo > loadedUsers;
    void* ptr = &loadedUsers;
    storage->Get( "LocalLoginsPasswords", ptr, sizeOfLoadedUsers );  // TODO:Use serializator
    authorizator = new AuthorizatorByLoginPassword( loadedUsers );
    storage = new File();
};

Core::~Core() {
    size_t sizeOfLoadedOldUsers;
    std::vector< authInfo > loadedOldUsers;
    void* ptr = &loadedOldUsers;
    storage->Get( "LocalLoginsPasswords", ptr, sizeOfLoadedOldUsers );  // TODO:Use serializator
//    std::vector< authInfo > gotNewUsers = authorizator->GotUsers();  // TODO: Save new users
/*    if( gotNewUsers != loadedOldUsers ){
        storage->Set( "LocalLoginsPasswords", gotNewUsers, gotNewUsers.size() * sizeof( gotNewUsers[0] ) );  // TODO:Use serializator
    } */
    delete authorizator;
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
        return UNKNOWN_ERROR;  // TODO: Throw exception
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

