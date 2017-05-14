#ifndef API_Interface_h
#define API_Interface_h

#include <map>

#include "core/API/APIs.h"

class APIInterface : API {
public:
    APIInterface() : api();
    /// Залогинивает пользователя с login, password
    status Login( std::string login, std::string password ) = 0;
    /// Разлогинивает текущего пользователя
    status Logout() = 0;
    /// Отправляет сообщение от текущего пользователя, если авторизован
    status SendMessage( std::map<std::string, std::string> params ) = 0;
    /// Показывает n последних сообщений от пользователя user
    status ShowMessages( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status AddFriend( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status GetFriends( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status DeleteFriend( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status GetWall( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status PostWall( std::map<std::string, std::string> params ) = 0;
    /// TODO
    status ( std::map<std::string, std::string> params ) = 0;
    // TODO

protected:
    /// Статусы возврата функций
    API api;
    enum status {
        OK,
        ERROR,
    };
};


#endif /* API_Interface_h */

