#include <string>
#include <fstream>

#include "types.h"
#include "file.h"

// Методы File

File::File() : Storage(), handler(nullptr) {};

File::~File()
{
    handler->close();
    delete handler;
}

File::File( char* data, size_t size ) : Storage( data, size ), handler(nullptr) {};

File::File( size_t size ) : Storage( size ), handler(nullptr) {};

File::File( File& file )
{
    handler = new FileHandler();
    handler = file.handler;
    delete file.handler;
}

File::File( File&& file )
{
    handler = file.handler;
}

Status File::Set( std::string key, char* data, size_t bytes )
{
    handler->set_filename(key);
    handler->open();
    handler->write(data, bytes);
    handler->close();
    return OK;
}

Status File::Get( std::string key, char*& data, size_t& bytes )
{
    handler->set_filename(key);
    handler->open();
    handler->read(data, bytes);
    handler->close();
    return OK;
}

// Методы FileHandler

FileHandler::FileHandler( std::string name ) : Handler(), file(nullptr), filename(name) {};

FileHandler::FileHandler() : Handler(), file(nullptr), filename("") {};

void FileHandler::open()
{
    file.open(filename, std::ios::binary | std::ios::app);
}

void FileHandler::close()
{
    file.close();
}

bool FileHandler::is_open()
{
    return file.is_open();
}

void FileHandler::set_filename( std::string name )
{
    filename = std::string(root_dir) + name;
}

std::string FileHandler::get_filename()
{
    return filename;
}

FileHandler::~FileHandler()
{
    file.close();
}
