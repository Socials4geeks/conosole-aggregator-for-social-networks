#ifndef request_h
#define request_h

#include <iostream>
#include <map>

// "get":"messages",
// "network":"VK",
// "count":"2",
// "filter":"",
// "sort":""
using std::string;

// enum information_type {MESSAGES, FRIENDS};
// enum network_type {VK, TELEGRAM};

struct Request {
    std::string account;
    std::string command;
    std::map<std::string, std::string> args;
};

#endif /* request_h */
