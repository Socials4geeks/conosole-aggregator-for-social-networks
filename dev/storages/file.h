#include "storages/storage.h"

/**
    @class File
    Хранилище на файловой системе
**/

class File : public Storage {
  provate:
    FileHandler* handler;
  public:
    File() : Storage(), handler(nullptr) {};
    /// Аллоцирующий конструктор, выделяющий сразу size байт под данные
    File( size_t size ) : Storage( size ), handler(nullptr) {};
    /// Конструктор, заполняющий буфер данными
    File( void* data, size_t bytes ) : Storage( data, size ), handler(nullptr) {};
    /// Принимает объект-сериализатор, который отвечает за представление данных в памяти
    File( Serialisator* serialisator ) : Storage( serialisator ), handler(nullptr) {};
    File( File& file );
    File( File&& file );
    /// Сохраняет bytes байтов данных data и возвращет handle
    virtual Handler save( void* data, size_t bytes );
    /// Возвращает указатель на загруженный объект данных
    virtual void* load( Handler &obj );
};

/**
    @class FileHandler
    Объект хранилища, а конкретно, оболочка над FILE*
**/

class FileHandler : Handler {
  protected:
    FILE* handler;
    std::string filename;
  public:
    void FileHandler() : Handler(), handler(nullptr), filename("") {};
    /// Конструктор, инициализирующий название файла
    void FileHandler( std::string name ) : Handler(), handler(nullptr), filename(name) {};
    void set_filename( std::string name );
    std::string get_filename();
    /// Открыть объект хранилища
    virtual void open();
    /// Закрыть объект хранилища
    virtual void close();
    /// Открыт ли объект хранилища
    virtual void is_open();
};
