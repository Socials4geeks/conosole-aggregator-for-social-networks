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
    
    int PrintHello();
    virtual int PrintMessages( Response data ) = 0;
    virtual int PrintWall( Response data ) = 0;
    virtual int PrintFriends( Response data ) = 0;


    virtual Request Input() = 0;
};

#endif /* interfaces_h */
