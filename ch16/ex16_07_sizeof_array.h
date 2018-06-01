#ifndef CP5_EX16_07_SIZEOF_ARRAY_H_
#define CP5_EX16_07_SIZEOF_ARRAY_H_

template <typename T, unsigned N>
constexpr unsigned SizeOfArray(const T (&arr)[N])
{
    return N;
}

#endif // CP5_EX16_07_SIZEOF_ARRAY_H_
