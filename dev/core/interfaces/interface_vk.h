#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>



class InterfaceVK : public Interface {
public:
    InterfaceVK();
    ~InterfaceVK();

    int PrintMessages( params data );
    int PrintWall( params data );
    int PrintFriends( params data );

    virtual Request Input();
};

#endif /* interface_vk_h */
