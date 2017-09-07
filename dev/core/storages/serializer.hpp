#ifndef SERIALISATOR_HPP
#define SERIALISATOR_HPP

template<class T>
char* Serializer<T>::encode( T& data )
{
    return (char *)&data;
}

template<class T>
T Serializer<T>::decode( char* data )
{
    return *(T*)data;
}

#endif  // SERIALISATOR_HPP
