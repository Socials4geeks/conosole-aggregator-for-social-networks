#ifndef interface_vk_h
#define interface_vk_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "termcolor.h"
#include "types.h"
#include "interfaces.h"
#include "interface_typical.h"


/**
* Интерфейс для ВК, практически без изменений наследует типичный интерфейс.
*
*/
class InterfaceVK : public InterfaceTypical {
public:
    InterfaceVK();
    virtual ~InterfaceVK();
};

#endif /* interface_vk_h */
