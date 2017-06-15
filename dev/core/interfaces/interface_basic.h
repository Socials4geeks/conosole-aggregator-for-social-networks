#ifndef interface_basic_h
#define interface_basic_h

#include <iostream>
#include "termcolor.h"
#include "types.h"
#include "interfaces.h"
#include <vector>


/**
* Интерфейс, используемый, когда пользователь не залогинен ни в одной соц. сети.
*
*/
class InterfaceBasic : public Interface {
public:
    InterfaceBasic();
    ~InterfaceBasic();

    virtual Status PrintMessages( Response data );
    virtual Status PrintFriends( Response data );
    virtual Status PrintWall( Response data );

    Request Input();

private:
    Status PrintURL( Response data );  ///< Отобразить ссылку для авторизации.
};

#endif /* interface_basic_h */
