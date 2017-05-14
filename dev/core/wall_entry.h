#ifndef wall_entry_h
#define wall_entry_h
#include <iostream>
#include <ctime>

using std::string;

struct WallEntry {
    string author;
    string body;
    string pub_date;  // TODO: заменить бы на time_t.
    int rating;
};

#endif /* wall_entry_h */
