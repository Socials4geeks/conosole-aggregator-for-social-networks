#ifndef authorization_h
#define authorization_h

class Authorizator {
public:
    
    Authorizator();
    ~Authorizator();

    virtual Session Login( std::string username, std::string password ) = 0;
    virtual int Logout( Session session ) = 0;

private:

    std::vector<std::pair<std::string, std::string> > users // Вектор из пар логин-паролей
};

#endif /*authorization_h*/
