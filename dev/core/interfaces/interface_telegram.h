#ifndef interface_telegram_h
#define interface_telegram_h

#include <iostream>
#include "termcolor.h"
#include "core/message.h"
#include "core/friend_entry.h"
#include "core/wall_entry.h"
#include "interfaces.h"
#include <vector>

class InterfaceTelegram : public Interface {
public:
    InterfaceTelegram();
    ~InterfaceTelegram();
};

#endif /* interface_telegram_h */
