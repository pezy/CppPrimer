#include "ex16_28_shared_ptr.h"
#include <iostream>

struct Foo {
    Foo() { std::cout << "Foo()\n"; }
    ~Foo() { std::cout << "~Foo()\n"; }
};

struct D {
    void operator()(Foo* p) const
    {
        std::cout << "Call delete from function object...\n";
        delete p;
    }
};

int main()
{
    {
        std::cout << "constructor with no managed object\n";
        SharedPtr<Foo> sh1;
    }

    {
        std::cout << "constructor with object\n";
        SharedPtr<Foo> sh2(new Foo);
        SharedPtr<Foo> sh3(sh2);
        std::cout << sh2.use_count() << '\n';
        std::cout << sh3.use_count() << '\n';
    }

    {
        std::cout << "constructor with object and deleter\n";
        SharedPtr<Foo> sh4(new Foo, D());
        SharedPtr<Foo> sh5(new Foo, [](Foo* p) {
            std::cout << "Call delete from lambda...\n";
            delete p;
        });
    }
}