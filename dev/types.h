#ifndef types_h
#define types_h

typedef std::pair< std::string, std::string > AuthInfo;

typedef std::map< std::string, std::string > Params;

typedef enum {
    UNKNOWN,
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
    Params Params;
    Request() {
        Action = TypeOfAction::UNKNOWN;
    }
} Request;

typedef struct {
    std::string IdOfRemoteAccount;
    TypeOfResponse Type;
    std::vector< Params > Params;
    Request() {
        Type = typeOfResponse::ERROR;
    }
} Response;

typedef enum {
    OK,
    ERROR
} Status;

class NotImplementedYet( std::exception ) {};

#endif /* types_h */
