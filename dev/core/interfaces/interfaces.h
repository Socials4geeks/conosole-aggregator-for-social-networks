/**
\file
\brief Описание базового класса для польозвательских интерфейсов.
*
* Описание базовый класса для интерфейсов разных соц. сетей для ввода-вывода информации пользователю.
*
*/

#ifndef interfaces_h
#define interfaces_h

#include <vector>
#include <map>
#include "types.h"


/**
* Абстрактный базовый класс для интерфейсов разных соц. сетей для ввода-вывода информации пользователю.
*/
class Interface {
public:
    Interface();
    ~Interface();

    std::string name_of_social_network;  ///< Название соц. сети.
    
    Status PrintHello();
    virtual Status PrintMessages( Response data ) = 0;  ///< Отобразить список сообщений из какого-то диалога.
    virtual Status PrintWall( Response data ) = 0;  ///< Отобразить сообщения со стены(при её наличии).
    virtual Status PrintFriends( Response data ) = 0;  ///< Отобразить список друзей.
    virtual Status PrintError( Response data ) = 0;  ///< Отобразить ошибку, если что-то пошло не так.


    virtual Request Input() = 0;  ///< Получить команду от пользователя.
};

#endif /* interfaces_h */
