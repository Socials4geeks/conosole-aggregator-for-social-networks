#include "storages/file.h"

// Методы File

File::File( File& file )
{
    //TODO
}

File::File( File&& file )
{
    //TODO
}

Handler File::save( void* data, size_t bytes )
{
    Serialiser<fstream> serialiser();
    void* data = serialiser.encode( data );
    //TODO
}

void* File::load( Handler &obj )
{
    //TODO
}

// Методы FileHandler

void FileHandler::open()
{
    //TODO
}

void FileHandler::close()
{
    //TODO
}

void FileHandler::is_open()
{
    //TODO
}

void FileHandler::set_filename( std::string name )
{
    //TODO
}

std::string FileHandler::get_filename()
{
    //TODO
}
