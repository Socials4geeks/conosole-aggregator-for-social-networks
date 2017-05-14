#ifndef message_h
#define message_h
#include <iostream>
#include <ctime>

using std::string;

struct Message {
    string title;
    string username;
    bool readState;  // Точно ли хватит булеана?
    string datetime;  // TODO: заменить бы на time_t.
    string body;
};

#endif /* message_h */
