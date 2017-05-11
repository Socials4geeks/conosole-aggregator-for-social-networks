#ifndef SERIALISATOR_HPP
#define SERIALISATOR_HPP

template<>
void* Serialisator<int>::encode( T data )
{
    return &data;
}

template<>
T Serialisator<int>::decode( void* data )
{
    return *data;
}

// TODO: Дописать сериализаторы для других базовых типов C++

#endif  // SERIALISATOR_HPP
