#include "authorization/authorization.h"
    
Authorizator::Authorizator(std::vector < authInfo > UsersFromStorage ): users( UsersFromStorage ) { };

Authorizator::~Authorizator() {
    Core.storage.Set( "LoginsPasswords", users )  //TODO обращение к кору такое себе
}
