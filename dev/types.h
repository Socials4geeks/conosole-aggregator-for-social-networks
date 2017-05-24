#ifndef types_h
#define types_h

#include <map>
#include <vector>

typedef std::pair< std::string, std::string > authInfo;

typedef std::map< std::string, std::string > params;

typedef enum {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS
} typeOfResponse;

typedef struct {
    std::string IdOfRemoteAccount;
    std::string Action;
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
