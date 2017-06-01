#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <map>
#include "types.h"

class Interface {
public:
    Interface();
    ~Interface();

    std::string name_of_social_network;
    
    Status PrintHello();
    virtual Status PrintMessages( Response data ) = 0;
    virtual Status PrintWall( Response data ) = 0;
    virtual Status PrintFriends( Response data ) = 0;

    virtual Request Input() = 0;
};

#endif /* interfaces_h */
