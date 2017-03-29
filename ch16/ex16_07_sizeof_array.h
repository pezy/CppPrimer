/*
================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

a `constexpr` template that returns the size of a given array.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>
================================================================================
*/

#ifndef CP5_EX16_07_SIZEOF_ARRAY_H_
#define CP5_EX16_07_SIZEOF_ARRAY_H_

template <typename T, unsigned N>
constexpr unsigned SizeOfArray(const T (&arr)[N])
{
    return N;
}

#endif // CP5_EX16_07_SIZEOF_ARRAY_H_
