#ifndef interfaces_h
#define interfaces_h

#include "core/message.h"
#include "core/friend_entry.h"
#include "core/wall_entry.h"
#include <vector>

class Interface {
public:
    Interface();
    ~Interface();

    int PrintHello();
    virtual int PrintMessages( std::vector<Message> data ) = 0;
    virtual int PrintWall( std::vector<WallEntry> data ) = 0;
    virtual int PrintFriends( std::vector<FriendEntry> data ) = 0;
};

#endif /* interfaces_h */
