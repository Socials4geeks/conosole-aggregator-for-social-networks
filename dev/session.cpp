#include "session.h"


Session::Session() {
    //TODO
};

Session::Session( std::string login ) : 
    localLogin( login ) {};

Session::Session( std::string login, Settings settings ) : 
    localLogin( login ),
    user_settings( settings ) {};

