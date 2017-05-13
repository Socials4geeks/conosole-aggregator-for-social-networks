#ifndef message_h
#define message_h
#include <ctime>

#include interface.h

using std::string;

struct Message {
    string title;
    string username;
    bool readState;  // Точно ли хватит булеана?
    time_t datetime;
    string body;
};

#endif
