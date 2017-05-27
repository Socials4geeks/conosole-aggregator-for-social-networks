#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>


class InterfaceVK : public InterfaceTypical {
public:
    InterfaceVK();
    ~InterfaceVK();

    int PrintMessages( Response data );
    int PrintWall( Response data );
    int PrintFriends( Response data );
    int PrintError( Response data );

    virtual Request Input();
};

#endif /* interface_vk_h */
