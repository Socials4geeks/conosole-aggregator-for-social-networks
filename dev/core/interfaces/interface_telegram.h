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
    ~InterfaceTelegram();

    virtual Status PrintMessages( Response data );
    virtual Status PrintWall( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintError( Response data );

    virtual Request Input();
};

#endif /* interface_telegram_h */
