#ifndef Application_h
#define Application_h

#include <vector>
#include <string>

#include "core.h"
#include "storages.h"
#include "session.h"
#include "interfaces.h"
#include "authorization.h"

class Application {
public:
    
    Application();
    ~Application();
    
private:
    Core core;
    std::vector< Interface > ui;
    Interface* curUi;
    std::string curSocialNetwork;
    
    void executeRequest( Request request );
    void output( Response response );
};

#endif /* Application_h */
