#ifndef AUTH_BY_LOGIN_PASSWORD_H
#define AUTH_BY_LOGIN_PASSWORD_H

#include <vector>

#include "types.h"
#include "authorization.h"

class AuthorizatorByLoginPassword : public Authorizator {
public:
    AuthorizatorByLoginPassword( std::vector< authInfo > existingUsers );
    virtual ~AuthorizatorByLoginPassword();

    virtual void Signup( std::string username, std::string password );
    virtual Session Login( std::string username, std::string password );
    virtual Status Logout( Session session );
};


#endif /* AUTH_BY_LOGIN_PASSWORD_H */
