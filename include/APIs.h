#ifndef APIs_h
#define APIs_h

#include <string>
#include <map>

#include "types.h"

class API {
public:
    virtual bool is_authorized( int uid ) = 0;
    virtual Status authorize( int uid ) = 0;
    virtual int getUserId( authInfo loginPassword ) = 0;
    virtual Status SendMessage( authInfo loginPassword, std::string topic, std::string text, std::string recipient ) = 0;
    virtual params GetLastMessages( int uid ) = 0;
    virtual ProfileInfo getProfileInfo() = 0;

private:
    std::map<int, std::string> tokens;
};

#endif /* APIs_h */
