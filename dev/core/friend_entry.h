#ifndef friend_entry_h
#define friend_entry_h
#include <iostream>
#include <ctime>

using std::string;

struct FriendEntry {
    string username;
    bool isOnline;
    string lastEnter;  // TODO: заменить бы на time_t.
};

#endif /* friend_entry_h */
