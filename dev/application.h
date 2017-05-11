
#ifndef Application_h
#define Application_h

#include "core.h"

class Application {
public:
    
    Application();
    ~Application();
    
    int Start();
    
private:
    Core core;
    
};

#endif /* Application_h */
