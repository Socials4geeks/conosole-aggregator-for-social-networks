#ifndef authorization_h
#define authorization_h

#include "types.h"
#include "session.h"

class Authorizator {
public:

    Authorizator();    
    Authorizator(std::vector< authInfo > UsersFromStorage );
    virtual ~Authorizator();

    virtual Status Signup( std::string username, std::string password ) = 0;
    virtual Session Login( std::string username, std::string password ) = 0; //TODO: Должна возвращать сессию с вектором удалённых аккаунтов загруженных с диска
    
    std::vector< authInfo > GetUsers();

protected:

    std::vector< authInfo > users; // Вектор из пар логин-паролей
};

#endif /*authorization_h*/
