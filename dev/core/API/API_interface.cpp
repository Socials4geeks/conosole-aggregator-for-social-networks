#include "API_interface.h"
#include "types.h"

APIInterface::APIInterface() {
    
}

// TODO: recipient => recipients
Status APIInterface::SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    if( code == OK ) {
        code = api->SendMessage( loginPassword, topic, text, recipient );
        if( code == OK ) {
            Response.Type = ACCEPT;
        }
    }
    return code;
}

Status APIInterface::ShowMessages( authInfo loginPassword, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    if( code == OK ) {
        std::vector<Message> msgs = api->GetLastMessages( uid );
        for( int i = 0; i < msgs.size(); i++ ) {
            Response.Params[i]["mid"] = msgs[i].mid;
            Response.Params[i]["date"] = msgs[i].date;
            Response.Params[i]["out"] = msgs[i].out;
            Response.Params[i]["uid"] = msgs[i].uid;
            Response.Params[i]["read_state"] = msgs[i].read_state;
            Response.Params[i]["title"] = msgs[i].title;
            Response.Params[i]["body"] = msgs[i].body;
        }
        Response.Type = ACCEPT;
    }
    return code;
}

Status APIInterface::AddFriend(authInfo loginPassword, std::string idOfFriend, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

Status APIInterface::GetFriends(authInfo loginPassword, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

Status APIInterface::RemoveFriend(authInfo loginPassword, std::string idOfFriend, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

Status APIInterface::GetWall( authInfo loginPassword, Response& Response ) {
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

Status APIInterface::AddWall( authInfo loginPassword, std::string text, Response& Response ) {  // TODO: Replace std::string text to special struct for each SN
    int uid;
    Status code = checkCorrectLoginPassword( loginPassword, Response, uid );
    throw NotImplementedYet();
}

Status APIInterface::checkCorrectLoginPassword( authInfo loginPassword, Response& Response, int& uid ) {
    uid = api->getUserId(loginPassword);
    if( !uid ) {
        params params;
        params.insert( std::make_pair("reason", "Incorrect login or password") );
        Response.Params.push_back(params);
        return UNKNOWN_ERROR;
    }
    return _login_if_not_logined(uid);
}

Status APIInterface::_login_if_not_logined( int uid ) {
    if( !api->is_authorized(uid) ) {
        return api->authorize(uid);
    }
    return OK;
}
