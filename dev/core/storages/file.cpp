#include "storages/file.h"

#include <string>
#include <fstream>

#include "types.h"
// Методы File

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

status File::Set( std::string key, void* data, size_t bytes )
{
    handler.set_filename(key);
    handler.open();
    handler.write(data, bytes);
    handler.close();
    return OK;
}

status File::Get( std::string key, void*& data, size_t& bytes )
{
    handler.set_filename(key);
    handler.open();
    handler.read(data, bytes);
    handler.close();
    return OK;
}

// Методы FileHandler

void FileHandler::open()
{
    file.open(filename, ios::binary | ios::app);
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
