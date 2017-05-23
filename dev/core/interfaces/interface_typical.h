#ifndef interface_Typical_h
#define interface_Typical_h

#include <iostream>
#include "termcolor.h"
#include "core/message.h"
#include "core/friend_entry.h"
#include "core/wall_entry.h"
#include "core/request.h"
#include "core/interfaces.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>



class InterfaceTypical : public Interface {
public:
    InterfaceTypical();
    ~InterfaceTypical();

    int PrintMessages( std::vector<std::map<std::string, std::string>> data );
    int PrintWall( std::vector<std::map<std::string, std::string>> data );
    int PrintFriends( std::vector<std::map<std::string, std::string>> data );

    Request Input();
};

#endif /* interface_Typical_h */
