#ifndef authorization_h
#define authorization_h

class Authorizator {
public:
    
    Authorizator();
    ~Authorizator();

    virtual Session Login( std::string username, std::string password ) = 0;
    virtual int Logout( Session session ) = 0;
};

#endif /*authorization_h*/
