#ifndef Application_h
#define Application_h

#include <vector>
#include <string>

#include "core.h"
#include "storeges.h"
#include "session.h"
#include "authorization.h"

class Application {
public:
    
    Application();
    ~Application();
    
    int Start();
    
    
private:
    Core core;
    Storage storage;
    std::vector<Session> sessions;
    Authorizator authorizator;    
    
    int AddSession( Session successSession );
    int DeleteSession( Session session );

};

#endif /* Application_h */
