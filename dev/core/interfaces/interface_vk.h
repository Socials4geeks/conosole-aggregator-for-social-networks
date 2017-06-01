#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "termcolor.h"
#include "types.h"
#include "interfaces.h"
#include "interface_typical.h"

class InterfaceVK : public InterfaceTypical {
public:
    InterfaceVK();
    ~InterfaceVK();

    virtual Status PrintMessages( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintError( Response data );

    virtual Request Input();
};

#endif /* interface_vk_h */
