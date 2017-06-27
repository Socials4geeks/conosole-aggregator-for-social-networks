#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class NotImplemented : public std::exception {};
class NotAuthorized: public std::exception {};
class BadAuth: public std::exception {};

#endif  // EXCEPTIONS_H
