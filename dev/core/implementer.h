
#ifndef implementer_h
#define implementer_h

class Implementer{
public:

    Response ExecuteRequest( Request request  ); //Split on basic functional and API

private:
    
    BasicFunctions basicFunctional;
    std::map< std::string, APIInterface  > apiInterfaces;

};


#endif /* implementer_h */
