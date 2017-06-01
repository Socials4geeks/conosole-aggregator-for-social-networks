#include "storage.h"

#include <string>
#include <fstream>

#include "types.h"
/**
    @class File
    Хранилище на файловой системе
**/

class FileHandler;

const char root_dir[] = "/tmp/storages/";

class File : public Storage {
  public:
    File();
    /// Аллоцирующий конструктор, выделяющий сразу size байт под данные
    File( size_t size );
    /// Конструктор, заполняющий буфер данными
    File( void* data, size_t bytes );
    /// Принимает объект-сериализатор, который отвечает за представление данных в памяти
    File( File& file );
    File( File&& file );
    /// Сохраняет bytes байтов данных data по ключу key
    virtual Status Set( std::string key, void* data, size_t bytes );
    /// Возвращает указатель на загруженный объект данных по ключу key
    virtual Status Get( std::string key, void*& data, size_t& bytes );
  private:
    FileHandler* handler;
};

/**
    @class FileHandler
    Объект хранилища, а конкретно, оболочка над FILE*
**/

class FileHandler : Handler {
  public:
    FileHandler();
    /// Конструктор, инициализирующий название файла
    FileHandler( std::string name );
    void set_filename( std::string name );
    std::string get_filename();
    /// Открыть объект хранилища
    virtual void open();
    /// Закрыть объект хранилища
    virtual void close();
    /// Открыт ли объект хранилища
    virtual bool is_open();
    virtual void write(void* data, size_t size);
    virtual void read(void*& data, size_t& size);
  protected:
    std::fstream file;
    std::string filename;
};
