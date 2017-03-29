/*
================================================================================
C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/CppPrimer

Define your own versions of `begin` and `end` functions that take an array
argument work.

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>
================================================================================
*/

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
