#ifndef request_h
#define request_h

include <iostream>

// "get":"messages",
// "network":"VK",
// "count":"2",
// "filter":"",
// "sort":""
enum information_type {MESSAGES, FRIENDS};
enum network_type {VK, TELEGRAM};

struct Request {
    information_type get;
    network_type network;
    int number;
    string filter;

};

#endif /* request_h */
