#ifndef core_h
#define core_h

#include interface.h

class Core{
public:

    Storage storage;

    Core();
    ~Core();

    int RemoveSession( Session session );
    bool IsSessionActive( Session session );

private:
    std::vector< Session > sessions;

};

#endif /* core_h */
