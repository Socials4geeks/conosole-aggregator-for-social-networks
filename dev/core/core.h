#ifndef core_h
#define core_h

#include "authorization.h"
#include "types.h"
#include "session.h"
#include "implementer.h"
#include "storage.h"

class Core{
public:

    Core();
    ~Core();

    Response ExecuteRequest( Request request  ); //Validate session, loading from storage

private:

    Authorizator* authorizator;
    Storage* storage;
    std::vector< Session > sessions; //Session which user enetered
    Session activeSession;
    Implementer implementer;

    Status RemoveSession( Session session );
    bool IsSessionActive( Session session );
    bool wasLoadedUsers;
};

#endif /* core_h */
