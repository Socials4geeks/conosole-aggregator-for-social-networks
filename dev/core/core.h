#ifndef core_h
#define core_h

#include interface.h

class Core{
public:

    Core();
    ~Core();

    Response ExecuteRequest( Request request  ); 

private:

    Authorizator* authorizator;
    Storage storage;
    std::vector< Session > sessions; //Session which user enetered
    Session activeSession;
    Implementer implementer;

    int RemoveSession( Session session );
    bool IsSessionActive( Session session );
    Response ExecuteRequest( Request request  ); //Validate session, loading from storage
};

#endif /* core_h */
