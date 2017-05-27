#ifndef types_h
#define types_h

#include <map>
#include <vector>
#include <ctime>

typedef std::pair< std::wstring, std::wstring > authInfo;

typedef std::map< std::wstring, std::wstring > params;

typedef enum {
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
} TypeOfAction;

typedef enum {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS,
    ACCEPT,
    ERROR,
} TypeOfResponse; 

typedef struct Request {
    std::string IdOfRemoteAccount;
    TypeOfAction Action;
    params Params;
    Request() {
        Action = TypeOfAction::UNKNOWN;
    }
} Request;

typedef struct {
    std::string IdOfRemoteAccount;
    TypeOfResponse Type;
    std::vector< params > Params;
    Request() {
        Type = typeOfResponse::ERROR;
    }
} Response;

typedef enum {
    OK,
    ERROR
} Status;


/// API data structures

typedef std::pair<time_t, std::wstring> TokenInfo;

typedef std::vector< std::pair<std::wstring, std::wstring> > UrlParams;

typedef enum {
    NOT_DEFINED,
    WOMEN,
    MEN
} Sex;

struct ProfileInfo {
    int uid;
    std::wstring first_name;
    std::wstring last_name;
    std::wstring screen_name;
    Sex sex;
    std::wstring home_town;
    std::wstring country;
    std::wstring city;
    std::wstring status;
    std::wstring phone;
};

struct Message {
    size_t mid;
    size_t date;
    bool out;
    size_t uid;
    bool read_state;
    std::wstring title;
    std::wstring body;
};

/// Exceptions

class NotImplementedYet : public std::exception {};

struct TemporaryBrowserAuthorisation : public std::exception {
    TemporaryBrowserAuthorisation( TokenInfo& access_token ) : access_token(access_token);
    TokenInfo& access_token;
    std::stirng authorisation_url;
};

#endif /* types_h */
