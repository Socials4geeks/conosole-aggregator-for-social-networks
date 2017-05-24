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

    int PrintMessages( std::vector<std::map<std::string, std::string>> data );
    int PrintFriends( std::vector<std::map<std::string, std::string>> data );
    int PrintWall( std::vector<std::map<std::string, std::string>> data );

    Request Input();
};

#endif /* interface_basic_h */
