#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <map>
#include "types.h"

class Interface {
public:
    Interface();
    ~Interface();

    int PrintHello();
    virtual int PrintMessages( std::vector<std::map<std::string, std::string>> data ) = 0;
    virtual int PrintWall( std::vector<std::map<std::string, std::string>> data ) = 0;
    virtual int PrintFriends( std::vector<std::map<std::string, std::string>> data ) = 0;

    virtual Request Input() = 0;
};

#endif /* interfaces_h */
