#ifndef types_h
#define types_h

#include <map>
#include <vector>

typedef std::pair< std::string, std::string > authInfo;

typedef std::map< std::string, std::string > params;

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

class NotImplementedYet : public std::exception {};

struct TemporaryBrowserAuthorisation : public std::exception {
    TemporaryBrowserAuthorisation( std::string& access_token ) : access_token(access_token);
    std::string& access_token;
    std::stirng authorisation_url;
};

typedef enum {
    NOT_DEFINED,
    WOMEN,
    MEN
} Sex;

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

#endif /* types_h */
