#ifndef interface_Typical_h
#define interface_Typical_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

#include "termcolor.h"
#include "types.h"
#include "interfaces.h"

class InterfaceTypical : public Interface {
public:
    InterfaceTypical();
    ~InterfaceTypical();

    virtual Status PrintMessages( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintFriends( Response data );
    Request Input();

private:
    template<typename Out>
    void split(const std::string &s, char delim, Out result);
    std::vector<std::string> split(const std::wstring &s, char delim);
    std::vector<std::string> split_to_tokens(std::wstring command);
    params split_to_kwargs(std::vector<std::wstring>& args);
};

#endif /* interface_Typical_h */
