#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "../message.h"
#include "../friend_entry.h"
#include "../wall_entry.h"
#include "interfaces.h"
#include <vector>
#include <algorithm>

class InterfaceVK : public Interface {
public:
    InterfaceVK();
    ~InterfaceVK();

    int PrintMessages( std::vector<Message> data );
    int PrintWall( std::vector<WallEntry> data );
    int PrintFriends( std::vector<FriendEntry> data );
};

#endif /* interface_vk_h */
