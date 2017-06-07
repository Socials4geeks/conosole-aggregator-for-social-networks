#ifndef types_h
#define types_h

#include <map>
#include <vector>
#include <ctime>
#include <string>

typedef std::pair< std::string, std::string > authInfo;

typedef std::map< std::string, std::string > params;

enum TypeOfAction {
    UNKNOWN,
    NEW_LOCAL_ACCOUNT,
    LOGIN_LOCAL_ACCOUNT,
    LOGOUT_LOCAL_ACCOUNT,
    SHOW_MESSAGES,
    SHOW_WALL,
    SHOW_FRIENDS,
    SEND_MESSAGE,
    ADD_WALL,
    ADD_FRIEND,
    REMOVE_FRIEND
};

enum TypeOfResponse {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS,
    ACCEPT,
    ERROR,
}; 

struct Request {
    std::string IdOfRemoteAccount;
    TypeOfAction Action;
    params Params;

    Request();
};

Request::Request() {
    Action = UNKNOWN;
}

struct Response {
    std::string IdOfRemoteAccount;
    TypeOfResponse Type;
    std::vector< params > Params;

    Response();
};

Response::Response() {
    Type = ERROR;
}

enum Status{
    OK,
    UNKNOWN_ERROR
};


/// API data structures

typedef std::pair<time_t, std::string> TokenInfo;

typedef std::vector< std::pair<std::string, std::string> > UrlParams;

enum Sex{
    NOT_DEFINED,
    WOMEN,
    MEN
};

struct ProfileInfo {
    int uid;
    std::string first_name;
    std::string last_name;
    std::string screen_name;
    Sex sex;
    std::string home_town;
    std::string country;
    std::string city;
    std::string status;
    std::string phone;
};

struct Message {
    size_t mid;
    size_t date;
    bool out;
    size_t uid;
    bool read_state;
    std::string title;
    std::string body;
};

/// Exceptions

class NotImplementedYet : public std::exception {};

struct TemporaryBrowserAuthorization : public std::exception {
    TemporaryBrowserAuthorization( TokenInfo& access_token ) : access_token(access_token) {};
    TokenInfo& access_token;
    std::string authorization_url;
};

#endif /* types_h */
