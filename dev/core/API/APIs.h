#ifndef APIs_h
#define APIs_h

#include <string>
#include <map>

class API {
public:
    status IsOnline();
    status SendToken( std::string token );
    status SendRequest( std::string request );
    std::map<std::string, std::string> GetData();

private:
    enum status {
        OK,
        ERROR,
    };
};

#endif /* APIs_h */
