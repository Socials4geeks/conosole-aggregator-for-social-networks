#include "storage.h"
#include <iostream>
#include <string>

Storage::Storage( Storage& storage ) {
    //TODO
}

Storage::Storage( Storage&& storage ) {
    //TODO
}

Handle Storage::save( void* data, size_t bytes ) {
    //TODO
}

void* Storage::load( Handle &obj ) {
    //TODO
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
