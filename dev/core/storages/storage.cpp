#include "storage.h"
#include "exceptions.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

Storage::Storage() : buffer(nullptr), buffer_size(0) {};

Storage::Storage( Storage& storage ) {
    buffer_size = storage.buffer_size;
    buffer = new char[buffer_size];
}

Storage::Storage( Storage&& storage ) {
    buffer_size = storage.buffer_size;
    storage.buffer_size = 0;
    buffer = new char[buffer_size];
    delete[] storage.buffer;
    memmove(buffer, storage.buffer, buffer_size);
}

Status Storage::Set( std::string key, char* data, size_t bytes ) {
    throw NotImplemented();
}

Status Storage::Get( std::string key, char*& data, size_t& bytes ) {
    throw NotImplemented();
}

Storage::Storage( size_t bytes ) {
    buffer_size = bytes;
    buffer = new char[buffer_size];
}

Storage::Storage( char* data, size_t bytes ) {
    buffer_size = bytes;
    buffer = new char[buffer_size];
    memmove(buffer, data, buffer_size);
}

Storage::~Storage() {
    delete[] buffer;
}
