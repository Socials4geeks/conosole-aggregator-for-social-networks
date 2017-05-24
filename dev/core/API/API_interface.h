#ifndef API_Interface_h
#define API_Interface_h

#include <map>
#include <string>

#include "core/API/APIs.h"

class APIInterface {
public:
    APIInterface();

protected:
    virtual status SendMessage( authInfo loginPassword,  std::string topic, std::string text, std::string recipient, response& Response );  // TODO: recipients => recipients
    /// Показывает n последних сообщений от пользователя user
    virtual status ShowMessages( authInfo loginPassword, response& Response );
    virtual status AddFriend(authInfo loginPassword, std::string idOfFriend, response& Response );
    virtual status GetFriends(authInfo loginPassword, response& Response );
    virtual status RemoveFriend(authInfo loginPassword, std::string idOfFriend, response& Response );
    virtual status GetWall( authInfo loginPassword, response& Response );
    virtual status AddWall( authInfo loginPassword, std::string text  );  // TODO: Replace std::string text to special struct for each SN

protected:
    API api;

private:
    void login_if_not_logined( authInfo loginPassword );
    status checkCorrectLoginPassword( authInfo loginPassword, response& Response, int& uid );
};


#endif /* API_Interface_h */

