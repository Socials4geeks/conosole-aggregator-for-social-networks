#ifndef types_h
#define types_h

typedef authInfo < std::pair< std::string, std::string > > 

typedef params std::map< std::string, std::string >

typedef typeOfResponse enum {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS
}

typedef Request struct {
    std::string IdOfRemoteAccount;
    std::string Action;
    params Params;
}

typedef Response struct {
    std::string IdOfRemoteAccount;
    typeOfResponse Type;
    std::vector< params > Params;
}

typedef status enum {
    OK,
    ERROR
};

#endif /* types_h */
