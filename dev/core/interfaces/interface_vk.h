#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "../message.h"
#include "../friend_entry.h"
#include "../wall_entry.h"
#include "interfaces.h"
#include <vector>

class Interface_VK : public Interface {
public:
    InterfaceVK();
    ~InterfaceVK();
};

#endif /* interface_vk_h */
