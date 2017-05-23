#include "authorisation/authorization.h"
    
Authorizator::Authorizator() {
    users = Core.storage.Pop( "LoginsPasswords" ) //TODO обращение к кору такое себе
}

Authorizator::~Authorizator() {
    Core.storage.Push( "LoginsPasswords", users )  //TODO обращение к кору такое себе
}
