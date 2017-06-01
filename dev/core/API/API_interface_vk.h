#ifndef API_Interface_h
#define API_Interface_h

#include <map>
#include <string>

#include "APIs.h"
#include "APIInterface.h"

class APIInterface_VK : APIInterface {
public:
    APIInterface_VK();
    ~APIInterface_VK();

    virtual Status SendMessage( authInfo loginPassword,  std::string topic, std::string text, std::string recipient, Response& response );  // TODO: recipients => recipients
    /// Показывает n последних сообщений от пользователя user
    virtual Status ShowMessages( authInfo loginPassword, Response& response );
    virtual Status AddFriend(authInfo loginPassword, std::string idOfFriend, Response& response );
    virtual Status GetFriends(authInfo loginPassword, Response& response );
    virtual Status RemoveFriend(authInfo loginPassword, std::string idOfFriend, Response& response );
    virtual Status GetWall( authInfo loginPassword, Response& response );
    virtual Status AddWall( authInfo loginPassword, std::string text  );  // TODO: Replace std::string text to special struct for each SN

private:
    virtual void login_if_not_logined( authInfo loginPassword );
    virtual Status checkCorrectLoginPassword( authInfo loginPassword, Response& response, int& uid );
};


#endif /* API_Interface_h */
