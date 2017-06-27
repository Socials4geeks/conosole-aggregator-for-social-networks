/**
\file
\brief Описание базового класса для польозвательских интерфейсов.
*
* Описание базовый класса для интерфейсов разных соц. сетей для ввода-вывода информации пользователю.
*
*/

#ifndef interfaces_h
#define interfaces_h

#include <string>

#include "types.h"

/**
* Абстрактный базовый класс для интерфейсов разных соц. сетей для ввода-вывода информации пользователю.
*/
class Interface {
public:
    Interface();
    virtual ~Interface();

    std::string name_of_social_network;  ///< Название соц. сети.
    
    virtual Status PrintMessages( Response data ) = 0;  ///< Отобразить список сообщений из какого-то диалога.
    virtual Status PrintWall( Response data ) = 0;  ///< Отобразить сообщения со стены(при её наличии).
    virtual Status PrintFriends( Response data ) = 0;  ///< Отобразить список друзей.
    virtual Status PrintError( Response data ) = 0;  ///< Отобразить ошибку, если что-то пошло не так.

    static Status PrintHello();

    virtual Request Input();  ///< Получить команду от пользователя.

private:
    std::vector<std::string> split_to_tokens(std::string command);  ///< Разделяет строку на подстроки, разделяя по пробелам, но учитывая пробелы в кавычках.
    TypeOfAction string_to_action(std::string str);
    params split_to_kwargs(std::vector<std::string>& args);  ///< Разделяет строку на параметры, включающие название параметра и аргумент.
};

#endif /* interfaces_h */
