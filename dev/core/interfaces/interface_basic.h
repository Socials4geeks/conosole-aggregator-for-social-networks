#ifndef interface_basic_h
#define interface_basic_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "interfaces.h"
#include <vector>

class InterfaceBasic : public Interface {
public:
    InterfaceBasic();
    ~InterfaceBasic();

    int PrintMessages( Response data );
    int PrintFriends( Response data );
    int PrintWall( Response data );
    int PrintURl( Response data);

    Request Input();
};

#endif /* interface_basic_h */
