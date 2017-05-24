#aifndef types_h
#define types_h

typedef authInfo < std::pair< std::string, std::string > > 

typedef params std::map< std::string, std::string >

typedef typeOdAction enum{
    SHOW_MESSAGES,
    SHOW_WALL,
    SHOW_FRIENDS,
    SEND_MESSAGE,
    ADD_WALL,
    ADD_FRIEND,
    REMOVE_FRIEND
}


typedef typeOfResponse enum {
    MESSAGES,
    WALL,
    FRIENDS,
    LOGIN_STATUS,
    ACCEPT,
    ERROR,
}

typedef Request struct {
    std::string IdOfRemoteAccount;
    typeOfAction Action;
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
