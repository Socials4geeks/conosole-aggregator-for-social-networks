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
    virtual int PrintMessages( params data ) = 0;
    virtual int PrintWall( params data ) = 0;
    virtual int PrintFriends( params data ) = 0;

    virtual Request Input() = 0;
};

#endif /* interfaces_h */
