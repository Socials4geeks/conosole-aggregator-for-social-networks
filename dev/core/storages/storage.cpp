#include "storage/storage.h"
#include <iostream>
#include <string>

#include "exceptions.h"

Storage::Storage() : buffer(nullptr), buffer_size(0) {};

Storage::Storage( Storage& storage ) {
    buffer_size = storage.buffer_size;
    buffer = new void[buffer_size];
}

Storage::Storage( Storage&& storage ) {
    buffer_size = storage.buffer_size;
    storage.buffer_size = 0;
    buffer = new void[buffer_size];
    delete[] storage.buffer;
    memmove(buffer, storage.buffer, buffer_size);
}

int Storage::Set( std::string key, void* data, size_t bytes ) {
    throw NotImplemented();
}

int Storage::Get( std::string key, void*& data, size_t& bytes ) {
    throw NotImplemented();
}

Storage::Storage( size_t bytes ) {
    buffer_size = bytes;
    buffer = new void[buffer_size];
}

Storage::Storage( void* data, size_t bytes ) {
    buffer_size = bytes;
    buffer = new void[buffer_size];
    memmove(buffer, data, buffer_size);
}

Storage::~Storage() {
    delete[] buffer;
    delete implementor;
}
