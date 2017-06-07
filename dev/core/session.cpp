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

bool Session::operator==( Session session ) {
    return localLogin == session.localLogin;
}

Session::~Session() {
    // TODO: Save changes authInfo for social networks and local too
}
