#include "core/core.h"

Core::Core() {
    std::vector< authInfo > loadedUsers = storage.Pop( "LocalLoginsPasswords" ); //Use serializator
    authorizator = new Authorizator( loadedUsers );
};

Core::~Core() {
    std::vector< authInfo > loadedOldUsers = storage.Pop( "LocalLoginsPasswords" ); //Use serializator
    std::vector< authInfo > gotNewUsers = authorizator->GotUsers();
    if( gotNewUsers != loadedOldUsers ) {
        storage.Push( "LocalLoginsPasswords" ); //Use serializator
    }
    delete authorizator;
};


Response Core::ExecuteRequest( Request request  ) {
    Response response;
    response.Type = ERROR;
    switch ( request.Action ) {
        case NEW_LOCAL_ACCOUNT:
            authorizator.Signup( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] );
            break; //Return response
        case LOGIN_LOCAL_ACCOUNT:
            ActiveSession = authorizator.Login( request.Params[ "LOCAL_USERNAME" ], request.Params[ "LOCAL_PASSWORD" ] );
            break; //Return response
        case LOGOUT_LOCAL_ACCOUNT:
            ActiveSession = Session();
            break; //Return response
        case SHOW_MESSAGES:
        case SHOW_WALL:
        case SHOW_FRIENDS:
        case SEND_MESSAGE:
        case ADD_WALL:
        case ADD_FRIEND:
        case REMOVE_FRIEND:
            authInfo tmp = ActionSession.GetAuthForApi( request.Params[ "SOCIAL_NETWORK_NAME" ]; //Handle exception NoAuthData
            request.Params[ "REMOTE_LOGIN" ] = tmp.first();
            request.Params[ "REMOTE_PASSWORD" ] = tmp.second();
            response = implementer.ExecuteRequest( request );
            return response;
            break;
        default:
            return response;

int Core::RemoveSession( Session session ) {
    if ( !IsSessionActive ) {
        return 1;
    }
    for ( auto i : sessions ) {
        if( i == session ) {
            //TODO Delete Session
        }
    }
    return 0;
}

bool Core::IsSessionActive( Session session ) {
    for ( auto i : sessions ) {
        if( i == session ){
            return true;
        }
    }
    return false;
}

