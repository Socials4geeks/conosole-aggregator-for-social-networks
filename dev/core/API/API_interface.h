#ifndef API_Interface_h
#define API_Interface_h

#include <map>
#include <string>

#include "APIs.h"

class APIInterface {
public:
    virtual Status SendMessage( authInfo loginPassword,  std::string topic, std::string text, std::string recipient, Response& response ) = 0;  // TODO: recipients => recipients
    /// Показывает n последних сообщений от пользователя user
    virtual Status ShowMessages( authInfo loginPassword, Response& response ) = 0;  // TODO: Show -> Get
    virtual Status AddFriend(authInfo loginPassword, std::string idOfFriend, Response& response ) = 0;
    virtual Status GetFriends(authInfo loginPassword, Response& response ) = 0;
    virtual Status RemoveFriend(authInfo loginPassword, std::string idOfFriend, Response& response ) = 0;
    virtual Status GetWall( authInfo loginPassword, Response& response ) = 0;
    virtual Status AddWall( authInfo loginPassword, std::string text, Response& response ) = 0;  // TODO: Replace std::string text to special struct for each SN

protected:
    API* api;

    virtual void login_if_not_logined( authInfo loginPassword ) = 0;
    virtual Status checkCorrectLoginPassword( authInfo loginPassword, Response& response, int& uid ) = 0;
};

#endif /* API_Interface_h */
