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

    virtual int PrintMessages( Response data );
    virtual int PrintFriends( Response data );
    virtual int PrintWall( Response data );
    virtual int PrintURl( Response data);

    Request Input();
};

#endif /* interface_basic_h */
