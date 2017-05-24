
#ifndef implementer_h
#define implementer_h

class Implementer{
public:

    Response ExecuteRequest( Request request  ); //Split on basic functional and API

private:
    
    std::vector<APIInterface> apiInterfaces;

};


#endif /* implementer_h */
