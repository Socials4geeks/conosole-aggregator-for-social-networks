#include "authorization.h"
    
Authorizator::Authorizator(): users() { };
Authorizator::Authorizator(std::vector < authInfo > UsersFromStorage ): users( UsersFromStorage ) { };

Authorizator::~Authorizator() {
 //   Core.storage.Set( "LoginsPasswords", users )  //TODO обращение к кору такое себе
}
