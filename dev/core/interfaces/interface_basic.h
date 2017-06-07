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

    virtual Status PrintMessages( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintURl( Response data );

    Request Input();

private:
    Status PrintURL( Response data );
};

#endif /* interface_basic_h */
