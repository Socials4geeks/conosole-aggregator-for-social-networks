#ifndef interface_basic_h
#define interface_basic_h

#include <iostream>
#include "termcolor.h"
#include "core/message.h"
#include "core/friend_entry.h"
#include "core/wall_entry.h"
#include "interfaces.h"
#include <vector>

class InterfaceBasic : public Interface {
public:
    InterfaceBasic();
    ~InterfaceBasic();

    int PrintMessages( std::vector<Message> data );
    int PrintFriends( std::vector<FriendEntry> data );
    int PrintWall( std::vector<WallEntry> data );
};

#endif /* interface_basic_h */
