#ifndef SERIALISATOR_HPP
#define SERIALISATOR_HPP

template<>
void* Serialisator<short>::encode( T data )
{
    return &data;
}

template<>
T Serialisator<int>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<long>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<long long>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<unsigned int>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<unsigned long>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<unsigned long long>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<float>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<double>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<long double>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<void>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<bool>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<short>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<unsigned short>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<wchar_t>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<char32_t>::decode( void* data )
{
    return *data;
}

template<>
T Serialisator<char16_t>::decode( void* data )
{
    return *data;
}

#endif  // SERIALISATOR_HPP
