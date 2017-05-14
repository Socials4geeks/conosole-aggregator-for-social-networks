#ifndef interfaces_h
#define interfaces_h

#include "../message.h"
#include <vector>

class Interface {
public:
    Interface();
    ~Interface();

    int PrintHello();
    virtual int PrintMessages( std::vector<Message> data ) = 0;
    virtual int PrintWall( std::vector<Message> data ) = 0;
    virtual int PrintFriends( std::vector<Message> data ) = 0;
};

#endif /* interfaces_h */
