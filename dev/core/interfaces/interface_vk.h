#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "dev/core/message.h"
#include "dev/core/friend_entry.h"
#include "dev/core/wall_entry.h"
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
