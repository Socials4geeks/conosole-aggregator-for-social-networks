#ifndef API_vk_h
#define API_vk_h

#include "core/API/APIs.h"

class API_vk : public API {
public:
    Status APIs::authorize( int uid );
    Status APIs::is_authorized( int uid );
    ProfileInfo getProfileInfo();
    int APIs::GetUserId( AuthInfo loginPassword );
    Status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient );
    Params GetLastMessages( int uid );

private:
    const char url[] = "https://api.vk.com/method/";
    const std::string STATE = "@#f6kmd;lk#@43J$@@#gj3346sdlkgw";
    const std::string VERSION = "5.64";
};

#endif /* API_vk_h */
