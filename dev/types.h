/**
\file
\brief Описание используемых типов, структур и перечислений.

Различные нестандартные структуры, необходимые в других файлах.

\todo Исправить "???" на нужные комментарии.
*/

#ifndef types_h
#define types_h

#include <map>
#include <vector>
#include <ctime>
#include <string>

typedef std::pair< std::string, std::string > authInfo;

typedef std::map< std::string, std::string > params;


/// Вариант запроса пользователя.
enum TypeOfAction {
    UNKNOWN,  ///< Неизвестное действие.
    NEW_LOCAL_ACCOUNT,  ///< Создать локальный аккаунт.
    LOGIN_LOCAL_ACCOUNT,  ///< Войти в локальный аккаунт.
    LOGOUT_LOCAL_ACCOUNT,  ///< Выйти из локального аккаунта.
    SHOW_MESSAGES,  ///< Показать сообщения из диалога.
    SHOW_WALL,  ///< Показать сообщения со стены.
    SHOW_FRIENDS,  ///< Показать список друзей.
    SEND_MESSAGE,  ///< Послать сообщение.
    ADD_WALL,  ///< Добавить запись на стену.
    ADD_FRIEND,  ///< Добавить контакт.
    REMOVE_FRIEND  ///< Удалить контакт.
};


/// Варинты ответа пользователю.
enum TypeOfResponse {
    MESSAGES,  ///< Сообщения из диалога.
    WALL,  ///< Записи со стены.
    FRIENDS,  ///< Список друзей.
    LOGIN_STATUS,  ///< Статус пользователя.
    ACCEPT,  ///< ???
    ERROR,  ///< Сообщение об ошибке.
};

/**
* \brief Запрос, посылаемый пользователем.
*/
struct Request {
    std::string IdOfRemoteAccount;  ///< Идентификатор аккаунта.
    TypeOfAction Action;  ///< Тип действия, совершаемого запросом.
    params Params;   ///< Параметры запроса. Могут быть невалидным, требуют проверки при получении.

    Request();
};


Request::Request() {
    Action = UNKNOWN;
}


/**
* \brief Ответ пользователю.
*/
struct Response {
    std::string IdOfRemoteAccount;  ///< Идентификатор аккаунта.
    TypeOfResponse Type;  ///< Тип ответа.
    std::vector< params > Params;  ///< Список параметров ответа.

    Response();
};

Response::Response() {
    Type = ERROR;
}

/// Возвращаемый статус многих функций.
enum Status {
    OK,  ///< Всё хорошо.
    UNKNOWN_ERROR  ///< Неизвестная ошибка.
};


/// API data structures

typedef std::pair<time_t, std::string> TokenInfo;


typedef std::vector< std::pair<std::string, std::string> > UrlParams;


/// Пол человека.
enum Sex {
    NOT_DEFINED,  ///< Не определён.
    WOMEN,  ///< Женский.
    MEN  ///< Мужской.
};


/// Информация о пользователе.
struct ProfileInfo {
    int uid;  ///< Id.
    std::string first_name;  ///< Имя.
    std::string last_name;  ///< Фамилия.
    std::string screen_name;  ///< Никнейм.
    Sex sex;  ///< Пол.
    std::string home_town;  ///< Родной город.
    std::string country;  ///< Страна.
    std::string city;  ///< Текущий город.
    std::string status;  ///< Статус.
    std::string phone;  ///< Номер телефона.
};


/// Структура, отвечающая за хранение собщения.
struct Message {
    size_t mid;  ///< ???
    size_t date;  ///< Дата отправки.
    bool out;  ///< Исходящее или входящее сообщение.
    size_t uid;  ///< ???
    bool read_state;  ///< Статус прочтения.
    std::string title;  ///< Заголовок сообщения.
    std::string body;  ///< Тело сообщения.
};

/// Exceptions

class NotImplementedYet : public std::exception {};

struct TemporaryBrowserAuthorization : public std::exception {
    TemporaryBrowserAuthorization( TokenInfo& access_token ) : access_token(access_token) {};
    TokenInfo& access_token;
    std::string authorization_url;
};

#endif /* types_h */
