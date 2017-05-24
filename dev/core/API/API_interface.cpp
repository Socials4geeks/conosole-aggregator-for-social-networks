#include "core/API/API_interface.h"
#include "types.h"

APIInterface::APIInterface() {

}

// TODO: recipient => recipients
status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient, response& Response ) {
    int uid;
    status = check_correct_login( loginPassword, Response, uid );
    if( code == status::OK ) {
        Response.Type = typeOfResponse::ACCEPT;
    }
    code = api.SendMessage( topic, text, recipient );
    if( code == status::OK ) {
        Response.Type = typeOfResponse::ACCEPT;
    }
    return code;
}

status ShowMessages( authInfo loginPassword, response& Response ) {
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );
    Response.Params = api.SendMessage( topic, text, uid );
    if( code == status::OK ) {
        Response.Type = typeOfResponse::ACCEPT;
    }
    return code;
}

status AddFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) {
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );
}

status GetFriends(authInfo loginPassword, response& Response ) {
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );

}

status RemoveFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) {
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );

}

status GetWall( authInfo loginPassword, response& Response ) {
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );

}

status AddWall( authInfo loginPassword, std::string text  ) {  // TODO: Replace std::string text to special struct for each SN
    int uid;
    status code = check_correct_login( loginPassword, Response, uid );

}

status APIInterface::checkCorrectLoginPassword( authInfo loginPassword, response& Response, int& uid ) {
    int uid = api.get_user_id(loginPassword);
    if( !uid ) {
        params params;
        params.insert( std::make_pair("reason", "Incorrect login or password") );
        Response.Params.push_back(params);
        return code;
    }
    status code = login_if_not_logined(uid);
    return code;
}

void APIInterface::login_if_not_logined( authInfo loginPassword ) {
    if( !api.authorized(loginPassword) ) {
        api.authorize(loginPassword);
    }
}
