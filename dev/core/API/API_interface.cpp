#include "core/API/API_interface.h"
#include "types.h"

APIInterface::APIInterface() {
    
}

// TODO: recipient => recipients
status APIInterface::SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    if( code == status::OK ) {
        code = api.SendMessage( topic, text, uid );
        if( code == status::OK ) {
            Response.Type = typeOfResponse::ACCEPT;
        }
    }
    return code;
}

status APIInterface::ShowMessages( authInfo loginPassword, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    if( code == status::OK ) {
        Response.Params = api.GetLastMessages( uid );
        Response.Type = typeOfResponse::ACCEPT;
    }
    return code;
}

status APIInterface::AddFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

status APIInterface::GetFriends(authInfo loginPassword, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

status APIInterface::RemoveFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

status APIInterface::GetWall( authInfo loginPassword, response& Response ) {
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

status APIInterface::AddWall( authInfo loginPassword, std::string text  ) {  // TODO: Replace std::string text to special struct for each SN
    int uid;
    status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

status APIInterface::checkCorrectLoginPassword( authInfo loginPassword, response& Response, int& uid ) {
    int uid = api.get_user_id(loginPassword);
    if( !uid ) {
        params params;
        params.insert( std::make_pair("reason", "Incorrect login or password") );
        Response.Params.push_back(params);
        return status::ERROR;
    }
    return _login_if_not_logined(uid);
}

status APIInterface::_login_if_not_logined( int uid ) {
    if( !api.authorized(uid) ) {
        return api.authorize(uid);
    }
    return status::OK;
}
