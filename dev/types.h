#ifndef types_h
#define types_h

typedef authInfo < std::pair< std::string, std::string > > 

typedef params std::map< std::string, std::string >

typedef Request struct {
    std::string IdOfRmoteAccount;
    std::string Action;
    params Params;
}

typedef status enum {
    OK,
    ERROR
};

#endif /* types_h */
