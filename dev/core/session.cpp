#include "session.h"


Session::Session(): EmptySession( true ) {
    //TODO
};

Session::Session( std::string login ) : 
    localLogin( login ),
    EmptySession( false ) {};

Session::Session( std::string login, params settings ) : 
    localLogin( login ),
    EmptySession( false ),
    user_settings( settings ) {};

authInfo Session::GetAuthForApi( std::string nameOfRemoteAccount ) {
    return authsForSocialNetworks[ "nameOfRemoteAccount" ];
}
    



