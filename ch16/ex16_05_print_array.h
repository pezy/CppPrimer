#ifndef CP5_EX16_05_PRINT_ARRAY_H_
#define CP5_EX16_05_PRINT_ARRAY_H_

#include <iostream>

template <typename T, unsigned N> void print_array(const T (&arr)[N])
{
    for (const auto& elem : arr) {
        std::cout << elem;
    }
    std::cout << std::endl;
}

#endif // CP5_EX16_05_PRINT_H_
