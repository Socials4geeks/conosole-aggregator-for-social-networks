#ifndef core_h
#define core_h

#include interface.h

class Core{
public:

    Core();
    ~Core();

    int RemoveSession( Session session );
    bool IsSessionActive( Session session );
    Response ExecuteRequest( Request request  ); //Validate session, loading from storage

private:

    Authorizator* authorizator;
    Storage storage;
    std::vector< Session > sessions;

};

#endif /* core_h */
