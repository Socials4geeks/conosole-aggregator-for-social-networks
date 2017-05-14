#ifndef interface_facebook_h
#define interface_facebook_h

#include <iostream>
#include "termcolor.h"
#include "../message.h"
#include "../friend_entry.h"
#include "../wall_entry.h"
#include "interfaces.h"
#include <vector>

class InterfaceFacebook : public Interface {
public:
    InterfaceFacebook();
    ~InterfaceFacebook();
};

#endif /* interface_facebook_h */
