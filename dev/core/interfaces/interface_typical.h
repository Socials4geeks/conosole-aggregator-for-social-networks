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
    ~InterfaceTypical();

    virtual Status PrintMessages( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintError( Response data );
    Request Input();

private:
    template<typename Out>
    void split(const std::string &s, char delim, Out result);  ///< Необходима в следующей функции, отдельно не используется. 
    std::vector<std::string> split(const std::string &s, char delim);  ///< Разделяет строку по символу delim.
    std::vector<std::string> split_to_tokens(std::string command);  ///< Разделяет строку на подстроки, разделяя по пробелам, но учитывая пробелы в кавычках.
    params split_to_kwargs(std::vector<std::string>& args);  ///< Разделяет строку на параметры, включающие название параметра и аргумент.
};

#endif /* interface_Typical_h */
