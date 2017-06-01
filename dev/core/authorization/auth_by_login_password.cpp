#include <vector>

#include "auth_by_login_password.h"
#include "types.h"

AuthorizatorByLoginPassword::AuthorizatorByLoginPassword( std::vector< authInfo > existingUsers ) {};

AuthorizatorByLoginPassword::~AuthorizatorByLoginPassword() {};

Session AuthorizatorByLoginPassword::Login( std::string username, std::string password ){
    std::pair< std::string, std::string > authData = std::make_pair< std::string, std::string >( username, password );
    for( auto i : users ){
        if( i == authData  )
            return Session();
    throw std::exception; //TODO Сделать исключение BadAuth
}

int AuthorizatorByLoginPassword::Logout( Session session ){
    return Core.RemoveSession(session) == 0  //TODO Придумать способ обойтись без образения к Core
}


