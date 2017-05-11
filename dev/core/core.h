#ifndef core_h
#define core_h

#include interface.h

class Core{
public:

    Core();
    ~Core();

private:
    std::vector<Interface> interfaces;
    Implementor implementor;
 
};

#endif /* core_h */
