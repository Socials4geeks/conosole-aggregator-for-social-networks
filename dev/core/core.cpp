#include "core/core.h"

Core() {

};

~Core() {

};

int Core::RemoveSession( Session session ) {
    if ( !IsSessionActive ) {
        return 1;
    }
    for ( auto i : sessions ) {
        if( i == session ) {
            //TODO Delete Session
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

