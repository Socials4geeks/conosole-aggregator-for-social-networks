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
    
private:
    Core core;
    std::vector< Interface > ui;
    Interface* curUi;
    std::string curSocialNetwork;
    
    void executeRequest( Request request );
    void output( Response response );
};

#endif /* Application_h */
