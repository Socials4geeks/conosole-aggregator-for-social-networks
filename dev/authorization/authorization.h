#ifndef authorization_h
#define authorization_h

class Authorizator {
public:
    
    Authorizator();
    ~Authorizator();

    virtual Session Login( std::string username, std::string password );
    virtual int Logout( Session session );
};

#endif /*authorization_h*/
