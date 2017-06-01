#ifndef implementer_h
#define implementer_h

#include "basic_functional.h"
#include "API_interface.h"

class Implementer{
public:
    Implementer();
    ~Implementer();

    Response ExecuteRequest( Request request ); //Split on basic functional and API

private:
    
    BasicFunctions basicFunctional;
    std::map< std::wstring, APIInterface* > apiInterfaces;
};


#endif /* implementer_h */
