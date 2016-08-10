/*
================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

Write a template version of the `print` function from 6.2.4 (p. 217)
that takes a reference to an array and can handle arrays of any size
and any element type.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>
================================================================================
*/

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
