#aifndef types_h
#define types_h

typedef < std::pair< std::string, std::string > > authInfo;

typedef std::map< std::string, std::string > params;

typedef enum{
    SHOW_MESSAGES,
    SHOW_WALL,
    SHOW_FRIENDS,
    SEND_MESSAGE,
    ADD_WALL,
    ADD_FRIEND,
    REMOVE_FRIEND
} typeOfAction;

typedef enum {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS,
    ACCEPT,
    ERROR,
} typeOfResponse; 

typedef struct {
    std::string IdOfRemoteAccount;
    typeOfAction Action;
    params Params;
} Request;

typedef struct {
    std::string IdOfRemoteAccount;
    typeOfResponse Type;
    std::vector< params > Params;
} Response;

typedef enum {
    OK,
    ERROR
} status;

#endif /* types_h */
