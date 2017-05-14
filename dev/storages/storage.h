#ifndef BASE_STORAGE_H
#define BASE_STORAGE_H

/** 
    @module storage
    Общий модуль, описывающий интерфейс хранилища и связанных классов
**/

class Storage;
class Handler;
struct Serialisator;

/**
    @class Storage
    Абстрактный базовый класс хранилища данных
    Является интерфейсом для остальных хранилищ
**/

class Storage {
  protected:
    void* buffer;  /// Промежуточный буфер
    size_t buffer_size;  /// Размер буфера
    std::vector<Hanler> handlers;

  public:
    Storage() : buffer(nullptr), buffer_size(0),
                serialisator(nullptr) {};
    Storage( Storage& storage );
    Storage( Storage&& storage );
    /// Аллоцирующий конструктор, выделяющий сразу size байт под данные
    Storage( size_t size );
    /// Конструктор, заполняющий буфер данными
    Storage( void* data, size_t bytes );
    /// Сохраняет bytes байтов данных data и возвращет handle
    virtual Handle save( void* data, size_t bytes ) = 0;
    /// Возвращает указатель на загруженный объект данных
    virtual void* load( Handle &obj ) = 0;
};

/**
    @class Handler
    Абстрактный базовый класс хендлера
    Предназначен для манипуляций с конкретным объектом хранилищем
    Является общим интерфейсом для всех хранилищ
**/

class Handler {
  public:
    void Handler() {};
    /// Открыть объект хранилища
    virtual void open() = 0;
    /// Закрыть объект хранилища
    virtual void close() = 0;
    /// Открыт ли объект хранилища
    virtual bool is_open() = 0;
};

/**
    @class Serialiser
    Абстрактный базовый шаблон класс сериализатора
    Отвечает за сериализацию данных в бинарное представление и обратно
    Для определения поведения для конкретных данных определить конкретизацию шаблона
**/

template <class T>
struct Serialisator {
    void* encode( T data );
    T decode( void* data );
};

#include "storage/serialisator.hpp"

#endif  // BASE_STORAGE_H
