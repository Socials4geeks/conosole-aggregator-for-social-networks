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

/**
* Базовый интерфейс для типичных соц. сетей, типа Телеграмма или ВК(без учёта стены), со стадартными списками друзей и сообщениями.
*
*/
class InterfaceTypical : public Interface {
public:
    InterfaceTypical();
    virtual ~InterfaceTypical();

    virtual Status PrintMessages( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintError( Response data );

private:
    template<typename Out>
    void split(const std::string &s, char delim, Out result);  ///< Необходима в следующей функции, отдельно не используется. 
    std::vector<std::string> split(const std::string &s, char delim);  ///< Разделяет строку по символу delim.
};

#endif /* interface_Typical_h */
