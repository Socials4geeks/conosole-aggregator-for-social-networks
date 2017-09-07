#include "authorization.h"
    
Authorizator::Authorizator(): users() { };
Authorizator::Authorizator(std::vector < authInfo > UsersFromStorage ): users( UsersFromStorage ) { };

Authorizator::~Authorizator() {

}

std::vector< authInfo > Authorizator::GetUsers() {
    return users;
}
