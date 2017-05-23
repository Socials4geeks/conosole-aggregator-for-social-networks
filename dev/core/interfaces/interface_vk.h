#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "core/message.h"
#include "core/friend_entry.h"
#include "core/wall_entry.h"
#include "core/request.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>



class InterfaceVK : public Interface {
public:
    InterfaceVK();
    ~InterfaceVK();

    int PrintMessages( std::vector<Message> data );
    int PrintWall( std::vector<WallEntry> data );
    int PrintFriends( std::vector<FriendEntry> data );

    Request Input();
};

#endif /* interface_vk_h */
