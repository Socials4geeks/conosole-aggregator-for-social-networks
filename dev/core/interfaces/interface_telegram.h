#ifndef interface_telegram_h
#define interface_telegram_h

#include <iostream>
#include <vector>

#include "termcolor.h"
#include "interface_typical.h"

/**
* Интерфейс для Телеграма, практически без изменений наследует типичный интерфейс.
*
*/
class InterfaceTelegram : public InterfaceTypical {
public:
    InterfaceTelegram();
    virtual ~InterfaceTelegram();
};

#endif /* interface_telegram_h */
