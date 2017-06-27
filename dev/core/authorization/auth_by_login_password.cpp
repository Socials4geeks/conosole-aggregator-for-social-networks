#include <vector>

#include "auth_by_login_password.h"
#include "types.h"
#include "exceptions.h"

AuthorizatorByLoginPassword::AuthorizatorByLoginPassword( std::vector< authInfo > existingUsers ) {};

AuthorizatorByLoginPassword::~AuthorizatorByLoginPassword() {};

Status AuthorizatorByLoginPassword::Signup( std::string username, std::string password ) {
    for( auto i : users ) {
        if ( username == i.first ) {
            return UNKNOWN_ERROR;
        }
    }
    authInfo signUpData = std::make_pair( username, password );
    users.push_back( signUpData );
    return OK;
};

Session AuthorizatorByLoginPassword::Login( std::string username, std::string password ) {
    std::pair< std::string, std::string > authData = std::make_pair( username, password );
    for( auto i : users ) {
        if( i == authData  ) {
            return Session( username );
        }
    }
    throw BadAuth();
}


