#include "core/core.h"

Core() {
    std::vector< authInfo > loadedUsers = storage.Get("LocalLoginsPasswords");  // TODO:Use serializator
    authorizator = new Authorizator(loadedUsers);
};

~Core() {
    std::vector< authInfo > loadedOldUsers = storage.Get("LocalLoginsPasswords");  // TODO:Use serializator
    std::vector< authInfo > gotNewUsers = authorizator->GotUsers();
    if( gotNewUsers != loadedOldUsers ){
        storage.Set("LocalLoginsPasswords", gotNewUsers);  // TODO:Use serializator
    }
    delete authorizator;
};

int Core::RemoveSession( Session session ) {
    if ( !IsSessionActive ) {
        return 1;
    }
    for ( auto i : sessions ) {
        if( i == session ) {
            // TODO Delete Session
        }
    }
    return 0;
}

bool Core::IsSessionActive( Session session ) {
    for ( auto i : sessions ) {
        if( i == session ){
            return true;
        }
    }
    return false;
}

