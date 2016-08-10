/*
================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

Write a template that acts like the library `find` algorithm.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>
================================================================================
*/

#ifndef CP5_EX16_04_FIND_H_
#define CP5_EX16_04_FIND_H_

template <typename InputIt, typename T>
InputIt Find(InputIt begin, InputIt end, const T& value)
{
    for (; begin != end; ++begin) {
        if (*begin == value) {
            return begin;
        }
    }
    return end;
}

#endif // CP5_EX16_04_FIND_H_
