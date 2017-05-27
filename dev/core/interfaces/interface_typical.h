#ifndef interface_Typical_h
#define interface_Typical_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>


class InterfaceTypical : public Interface {
public:
    InterfaceTypical();
    ~InterfaceTypical();

    int PrintMessages( Response data );
    int PrintWall( Response data );
    int PrintFriends( Response data );

    Request Input();
};

#endif /* interface_Typical_h */
