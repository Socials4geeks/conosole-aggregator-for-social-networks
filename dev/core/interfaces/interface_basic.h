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

    int PrintMessages( params data );
    int PrintFriends( params data );
    int PrintWall( params data );

    Request Input();
};

#endif /* interface_basic_h */
