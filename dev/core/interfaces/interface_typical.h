#ifndef interface_Typical_h
#define interface_Typical_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#include "termcolor.h"
#include "types.h"
#include "interfaces.h"

class InterfaceTypical : public Interface {
public:
    InterfaceTypical();
    ~InterfaceTypical();

    virtual int PrintMessages( Response data );
    virtual int PrintWall( Response data );
    virtual int PrintFriends( Response data );

    Request Input();
};

#endif /* interface_Typical_h */
