#ifndef session_h
#define session_h

#include <utility>
#include <vector>
#include <string>

typedef std::pair<std::string, std::string> LoginPassword;
typedef std::pair<std::string, LoginPassword> AuthInfo;
typedef std::map<std::string, std::string> Settings;

/**
    @class Session
    Содержит в себе всю информацию о пользователе, включая настройки,
    логины, пароли и так далее
**/
struct Session {
    Session() {};
    Session( LoginPassword login_password ) : login_password( login_password ) {};
    Session( LoginPassword login_password, Settings settings ) : login_password( login_password ),
                                                                 user_settings( settings ) {};
    Session( LoginPassword login_password, Settings settings ) : login_password( login_password ),
                                                                 user_settings( settings ) {};
    LoginPassword login_password;
    std::vector<AuthInfo> auths;
    Settings user_settings;
};

#endif /*session_h*/
