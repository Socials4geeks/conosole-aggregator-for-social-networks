#include <cstdio>

#include "core/API/API_vk.h"
#include "constats.h"

Status APIs::authorize( int uid ) {
    throw NotImplementedYet();
}

Status APIs::is_authorized( int uid ) {
    return Status::ERROR;  // TODO
}

int APIs::GetUserId( AuthInfo loginPassword ) {
    TemporaryBrowserAuthorisation exception( access_token );
    exception.authorisation_url = std::string(sprintf(httpFormatString, "https", "api.vk.com/authorization"))
        + std::string(sprintf(httpGetParams, "client_id", VK_APP_ID))
        + std::string(sprintf(httpGetParams, "display", "page"))
        + std::string(sprintf(httpGetParams, "scope", "friends")) 
        + std::string(sprintf(httpGetParams, "response_type", "token")) 
        + std::string(sprintf(httpGetParams, "v", VERSION)) 
        + std::string(sprintf(httpGetParams, "state", STATE)); 
    throw exception;
    ProfileInfo user = getProfileInfo();
    int uid = user.uid;
    tokens[uid] = access_token;
    return uid;
}

ProfileInfo getProfileInfo() {
   
}

Status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient ) {

}

Params GetLastMessages( int uid ) {

}
