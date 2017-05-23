#ifndef session_h
#define session_h

#include <utility>
#include <vector>
#include <string>

typedef std::pair<std::string, std::string> LoginPassword;
typedef std::pair<std::string, LoginPassword> AuthInfo; // First string is social network's name
//TODO Replace string to bin
typedef std::map<std::string, std::string> Settings;

/**
    @class Session
    Содержит в себе всю информацию о пользователе, включая настройки,
    логины, пароли и так далее
**/

class Session {
public:
    Session();
    Session( std::string login );
    Session( std::string login, Settings settings ) 

private:
    std::string localLogin;
    std::vector<AuthInfo> authsForSocialNetworks;
    Settings user_settings;
};

#endif /*session_h*/
