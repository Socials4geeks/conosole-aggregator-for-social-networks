#ifndef interface_telegram_h
#define interface_telegram_h

#include <iostream>
#include "termcolor.h"
#include "../message.h"
#include "interfaces.h"
#include <vector>

class InterfaceTelegram : public Interface {
public:
    InterfaceTelegram();
    ~InterfaceTelegram();
};

#endif /* interface_telegram_h */
