/*
=================================================================================

C++ Primer 5th Exercise Answer Source Code
Copyright (C) 2014-2015 github.com/pezy/Cpp-Primer

Base

If you have questions, try to connect with me: pezy<urbancpz@gmail.com>

=================================================================================
*/

#ifndef CP5_EX15_20_BASE_H_
#define CP5_EX15_20_BASE_H_

inline namespace EX20 {

class Base {
public:
    void pub_mem();
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base {
    int f() { return prot_mem; }
    char g() { return priv_mem; }
};

struct Priv_Derv : private Base {
    int f1() const { return prot_mem; }
};

}

#endif
