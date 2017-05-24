#ifndef API_Interface_h
#define API_Interface_h

#include <map>
#include <string>

#include "core/API/APIs.h"

class APIInterface {
public:
    APIInterface();
    /// Отправляет сообщение от текущего пользователя, если авторизован
    status SendMessage( authInfo loginPassword,  std::string topic, std::string text, std::string recipient, response& Response ) = 0;
    /// Показывает n последних сообщений от пользователя user
    status ShowMessages( authInfo loginPassword, response& Response ) = 0;
    /// TODO
    status AddFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) = 0;
    /// TODO
    status GetFriends(authInfo loginPassword, response& Response ) = 0;
    /// TODO
    status DeleteFriend(authInfo loginPassword, std::string idOfFriend, response& Response ) = 0;
    /// TODO
    status GetWall( authInfo loginPassword, response& Response ) = 0;
    /// TODO
    status AddWall( authInfo loginPassword, std::string text  ) = 0;  // TODO: Replace std::string text to special struct for each SN
    /// TODO

protected:
    std::vector< API > apis;
};


#endif /* API_Interface_h */

