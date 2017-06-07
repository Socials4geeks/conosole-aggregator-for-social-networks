#ifndef API_vk_h
#define API_vk_h

#include <string>
#include <vector>

#include <cpprest/uri_builder.h>

#include "APIs.h"
#include "types.h"

class API_vk : public API {
public:
    int Authorize( authInfo loginPassword );
    Status IsAuthorized( int uid );
    ProfileInfo getProfileInfo();
    Status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient );
    std::vector<Message> GetLastMessages( int uid );

private:
    const std::string STATE = "@#f6kmd;lk#@43J$@@#gj3346sdlkgw";
    const std::string VERSION = "5.64";

    std::map<int, TokenInfo> tokens;
    TokenInfo cur_access_token;

    web::uri::uri_builder buildApiUrl( std::string method, UrlParams uri_params={}, bool is_private=false );
};

#endif /* API_vk_h */
