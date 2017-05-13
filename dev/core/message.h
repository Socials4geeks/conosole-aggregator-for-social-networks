#ifndef message_h
#define message_h
#include <iostring>
#include <ctime>

using std::string;

struct Message {
    string title;
    string username;
    bool readState;  // Точно ли хватит булеана?
    time_t datetime;
    string body;
};

#endif /* message_h */
