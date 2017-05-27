#include "storages/storage.h"

#include <string>
#include <fstream>

#include "types.h"
/**
    @class File
    Хранилище на файловой системе
**/

const char root_dir[] = "/tmp/storages/"

class File : public Storage {
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
    /// Сохраняет bytes байтов данных data по ключу key
    virtual status Set( std::string key, void* data, size_t bytes );
    /// Возвращает указатель на загруженный объект данных по ключу key
    virtual status Get( std::string key, void*& data, size_t bytes );
  private:
    FileHandler* handler;
};

/**
    @class FileHandler
    Объект хранилища, а конкретно, оболочка над FILE*
**/

class FileHandler : Handler {
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
    virtual void write(void* data, size_t size);
    virtual void read(void*& data, size_t& size);
  protected:
    fstream file;
    std::string filename;
};
