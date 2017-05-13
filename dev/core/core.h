#ifndef core_h
#define core_h

#include interface.h

class Core{
public:
    Core();
    ~Core();
    //TODO

private:
    std::vector<Interface> interfaces;
    Implementor implementor;
};

#endif /* core_h */
