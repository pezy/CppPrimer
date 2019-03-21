#include <iostream>
#include <string>
#include <memory>

using std::shared_ptr;
using std::string;
using std::cout;
using std::endl;

template <typename T, typename ... Args>
shared_ptr<T> make_shared(Args && ... args)
{
   return shared_ptr<T>(new T(std::forward<Args>(args)...)); 
}

struct Foo
{
    Foo(int n = 0) noexcept : bar(n) {cout << "Foo: constructor, bar = " << bar << endl;}
    ~Foo() {cout << "Foo: destructor, bar = " << bar << endl;}
    int getBar() const noexcept {return bar;}
private:
    int bar;
};

int main()
{
    shared_ptr<Foo> sp = make_shared<Foo>(10);
    cout << "The first Foo's bar is " << sp->getBar() << endl;
    sp.reset(new Foo);
    cout << "The second Foo's bar is " << sp->getBar() << endl;
}

