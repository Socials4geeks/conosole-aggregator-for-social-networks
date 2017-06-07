#ifndef SERIALISATOR_HPP
#define SERIALISATOR_HPP

template<>
char* Serializer<short>::encode( short& data )
{
    return (char *)&data;
}

template<>
int Serializer<int>::decode( char* data )
{
    return *(int*)data;
}

template<>
long Serializer<long>::decode( char* data )
{
    return *(long*)data;
}

template<>
long long Serializer<long long>::decode( char* data )
{
    return *(long long*)data;
}

template<>
unsigned int Serializer<unsigned int>::decode( char* data )
{
    return *(unsigned int*)data;
}

template<>
unsigned long Serializer<unsigned long>::decode( char* data )
{
    return *(unsigned long*)data;
}

template<>
unsigned long long Serializer<unsigned long long>::decode( char* data )
{
    return *( unsigned long long* )data;
}

template<>
float Serializer<float>::decode( char* data )
{
    return *( float* )data;
}

template<>
double Serializer<double>::decode( char* data )
{
    return *( double* )data;
}

template<>
long double Serializer<long double>::decode( char* data )
{
    return *(long double*)data;
}

template<>
bool Serializer<bool>::decode( char* data )
{
    return *( bool* )data;
}

template<>
short Serializer<short>::decode( char* data )
{
    return *( short* )data;
}

template<>
unsigned short Serializer<unsigned short>::decode( char* data )
{
    return *( unsigned short* )data;
}

template<>
wchar_t Serializer<wchar_t>::decode( char* data )
{
    return *( wchar_t* )data;
}

template<>
char32_t Serializer<char32_t>::decode( char* data )
{
    return *( char32_t* )data;
}

template<>
char16_t Serializer<char16_t>::decode( char* data )
{
    return *( char16_t* )data;
}

#endif  // SERIALISATOR_HPP
