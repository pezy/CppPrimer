#ifndef CP5_EX16_06_BEGIN_END_H_
#define CP5_EX16_06_BEGIN_END_H_

template <typename T, unsigned N> T* Begin(T (&arr)[N])
{
    return arr;
}

template <typename T, unsigned N> T* End(T (&arr)[N])
{
    return arr + N;
}

#endif // CP5_EX16_06_BEGIN_END_H_
