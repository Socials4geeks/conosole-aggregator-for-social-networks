#ifndef interface_basic_h
#define interface_basic_h

#include <iostream>
#include "termcolor.h"
#include "../message.h"
#include "interfaces.h"
#include <vector>

class InterfaceBasic : public Interface {
public:
    InterfaceBasic();
    ~InterfaceBasic();

    int PrintMessages( std::vector<Message> data );
    int PrintFriends( std::vector<Message> data );
    int PrintWall( std::vector<Message> data );
};

#endif /* interface_basic_h */
