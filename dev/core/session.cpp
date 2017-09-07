#include "session.h"
#include "exceptions.h"

Session::Session(): EmptySession( true ) {
    
};

Session::Session( std::string login ) : 
    localLogin( login ),
    EmptySession( false ) {};

Session::Session( std::string login, params settings ) : 
    localLogin( login ),
    EmptySession( false ),
    user_settings( settings ) {};

authInfo Session::GetAuthForApi( std::string nameOfRemoteAccount ) {
    if( authsForSocialNetworks.find( nameOfRemoteAccount ) == authsForSocialNetworks.end() ) {
        throw NoAuthData();
    }
    return authsForSocialNetworks[ nameOfRemoteAccount ];
}

Status Session::AddAuthForApi( std::string nameOfRemoteAccount, authInfo loginPassword ) {
    authsForSocialNetworks[ nameOfRemoteAccount ] = loginPassword;
    return OK;
}

Status Session::DeleteAuthForApi( std::string nameOfRemoteAccount ) {
    auto i = authsForSocialNetworks.find( nameOfRemoteAccount );
    if( i == authsForSocialNetworks.end() ) {
            authsForSocialNetworks.erase( i );
            return OK;
    }
    return UNKNOWN_ERROR;
}

bool Session::operator==( Session session ) {
    return localLogin == session.localLogin;
}

bool Session::IsEmpty() {
    return EmptySession;
}

Session::~Session() {
    
}
