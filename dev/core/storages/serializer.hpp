#ifndef SERIALISATOR_HPP
#define SERIALISATOR_HPP

template<>
void* Serializer<short>::encode( short& data )
{
    return &data;
}

template<>
int Serializer<int>::decode( void* data )
{
    return *(int*)data;
}

template<>
long Serializer<long>::decode( void* data )
{
    return *(long*)data;
}

template<>
long long Serializer<long long>::decode( void* data )
{
    return *(long long*)data;
}

template<>
unsigned int Serializer<unsigned int>::decode( void* data )
{
    return *(unsigned int*)data;
}

template<>
unsigned long Serializer<unsigned long>::decode( void* data )
{
    return *(unsigned long*)data;
}

template<>
unsigned long long Serializer<unsigned long long>::decode( void* data )
{
    return *( unsigned long long* )data;
}

template<>
float Serializer<float>::decode( void* data )
{
    return *( float* )data;
}

template<>
double Serializer<double>::decode( void* data )
{
    return *( double* )data;
}

template<>
long double Serializer<long double>::decode( void* data )
{
    return *(long double*)data;
}

template<>
bool Serializer<bool>::decode( void* data )
{
    return *( bool* )data;
}

template<>
short Serializer<short>::decode( void* data )
{
    return *( short* )data;
}

template<>
unsigned short Serializer<unsigned short>::decode( void* data )
{
    return *( unsigned short* )data;
}

template<>
wchar_t Serializer<wchar_t>::decode( void* data )
{
    return *( wchar_t* )data;
}

template<>
char32_t Serializer<char32_t>::decode( void* data )
{
    return *( char32_t* )data;
}

template<>
char16_t Serializer<char16_t>::decode( void* data )
{
    return *( char16_t* )data;
}

#endif  // SERIALISATOR_HPP
