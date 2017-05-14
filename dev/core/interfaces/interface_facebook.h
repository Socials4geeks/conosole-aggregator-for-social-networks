#ifndef interface_facebook_h
#define interface_facebook_h

#include <iostream>
#include "termcolor.h"
#include "dev/core/message.h"
#include "dev/core/friend_entry.h"
#include "dev/core/wall_entry.h"
#include "interfaces.h"
#include <vector>

class InterfaceFacebook : public Interface {
public:
    InterfaceFacebook();
    ~InterfaceFacebook();
};

#endif /* interface_facebook_h */
