#ifndef session_h
#define session_h

#include <utility>
#include <vector>
#include <string>
#include <map>

#include "types.h"

/**
    @class Session
    Содержит в себе всю информацию о пользователе, включая настройки,
    логины, пароли и так далее
**/

class Session {
public:
    Session();
    Session( std::string login );
    Session( std::string login, params settings );
    ~Session();
    
    bool operator==( Session );
    authInfo GetAuthForApi( std::string nameOfRemoteAccount ); //Take id of SN. For example, "vk1"
    Status AddAuthForApi( std::string nameOfRemoteAccount, authInfo loginPassword );
    Status DeleteAuthForApi( std::string nameOfRemoteAccount );
    bool IsEmpty();

private:
    std::string localLogin;
    std::map< std::string, authInfo > authsForSocialNetworks;
    params user_settings;
    bool EmptySession;
};

#endif /*session_h*/
