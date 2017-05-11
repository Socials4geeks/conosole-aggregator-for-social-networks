#ifndef interfaces_h
#define interfaces_h

class Interface() {
public:
    Interface();
    ~Interface();

    int PrintHello();
    virtual int PrintMessages( std::map<std::string, std::string> data ) = 0;
    virtual int PrintWall( std::map<std::string, std::string> data ) = 0;
    virtual int PrintFriends( std::map<std::string, std::string> data ) = 0;
};

#endif /* interfaces_h */
