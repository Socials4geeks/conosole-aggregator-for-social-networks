#ifndef authorization_h
#define authorization_h

#include "types.h"

class Authorizator {
public:
    
    Authorizator(std::vector< authInfo > UsersFromStorage );
    ~Authorizator();

    virtual Session Login( std::string username, std::string password ) = 0;
    virtual int Logout( Session session ) = 0;

private:

    std::vector< authInfo > users; // Вектор из пар логин-паролей
};

#endif /*authorization_h*/
