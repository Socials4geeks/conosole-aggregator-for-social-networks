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

    virtual int PrintMessages( Response data );
    virtual int PrintWall( Response data );
    virtual int PrintFriends( Response data );
    virtual int PrintError( Response data );

    virtual Request Input();
};

#endif /* interface_vk_h */
