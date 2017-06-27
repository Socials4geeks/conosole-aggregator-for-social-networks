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
    virtual Status IsAuthorized( int uid );
    virtual ProfileInfo getProfileInfo();
    virtual Status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient );
    virtual std::vector<Message> GetLastMessages( int uid );

private:
    const std::string STATE = "@#f6kmd;lk#@43J$@@#gj3346sdlkgw";
    const std::string VERSION = "5.64";

    web::uri_builder buildApiUrl( std::string method, UrlParams uri_params=UrlParams(), bool is_private=false );
};

#endif /* API_vk_h */
