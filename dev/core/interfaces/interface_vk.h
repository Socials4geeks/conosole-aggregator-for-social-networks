#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>



class InterfaceVK : public Interface {
public:
    InterfaceVK();
    ~InterfaceVK();

    int PrintMessages( std::vector<std::map<std::string, std::string>> data );
    int PrintWall( std::vector<std::map<std::string, std::string>> data );
    int PrintFriends( std::vector<std::map<std::string, std::string>> data );

    virtual Request Input();
};

#endif /* interface_vk_h */
