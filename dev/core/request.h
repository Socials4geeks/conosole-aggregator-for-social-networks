#ifndef request_h
#define request_h

include <iostream>

// "get":"messages",
// "network":"VK",
// "count":"2",
// "filter":"",
// "sort":""
enum informationType {MESSAGES, FRIENDS};
enum networkType {VK, TELEGRAM, FACEBOOK};

struct Request {
    informationType get;
    networkType network;
    int number;
    string filter;

};

#endif /* request_h */
