#ifndef CP5_EX16_02_COMPARE_H_
#define CP5_EX16_02_COMPARE_H_

#include <cstring>

template <typename T> int compare(const T& v1, const T& v2)
{
    if (std::less<T>()(v1, v2)) {
        return -1;
    }

    if (std::less<T>()(v2, v1)) {
        return 1;
    }

    return 0;
}

template <unsigned N, unsigned M>
int compare(const char (&s1)[N], const char (&s2)[M])
{
    return strcmp(s1, s2);
}

#endif // CP5_EX16_02_COMPARE_H_
