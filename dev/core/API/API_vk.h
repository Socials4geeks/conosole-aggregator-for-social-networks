#ifndef API_vk_h
#define API_vk_h

#include <string>
#include <vector>

#include <cpprest/uribuilder.h>

#include "core/API/APIs.h"
#include "types.h"

class API_vk : public API {
public:
    int Authorize( AuthInfo loginPassword );
    Status IsAuthorized( int uid );
    ProfileInfo getProfileInfo();
    Status SendMessage( authInfo loginPassword, std::wstring topic, std::wstring text, std::wstring recipient );
    std::vector<Message> GetLastMessages( int uid );

private:
    constexpr std::wstring STATE = "@#f6kmd;lk#@43J$@@#gj3346sdlkgw";
    constexpr std::wstring VERSION = "5.64";

    std::map<int, TokenInfo> tokens;
    TokenInfo cur_access_token;

    web::uri::uri_builder buildApiUrl( std::wstring method, UrlParams uri_params={}, bool is_private=false );
};

#endif /* API_vk_h */
