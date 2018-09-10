# Chapter 15. Object-Oriented Programming

## Exercise 15.1

> What is a virtual member?

A member function should be dynamically bound by preceding its declaration.

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2

> How does the `protected` access specifier differ from `private`?

base class members:

- `private:`: base class itself and friends can access
- `protected`: base class itself, friends and derived classes can access

## Exercise 15.3

> Define your own versions of the `Quote` class and the `print_total` function.

[code](ex15_03_Quote.h)

## Exercise 15.4

> Which of the following declarations, if any, are incorrect? Explain why.

```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

- (a) incorrect, derive from itself
- (b) correct.
- (c) incorrect, A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list

## Exercise 15.5

> Define your own version of the `Bulk_quote` class.

[code](ex15_05_Bulk_quote.h)

## Exercise 15.6

> Test your `print_total` function from the exercises in 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects o that function.

[TEST](TEST.cpp)

## Exercise 15.7

> Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

[code](ex15_07_Limit_quote.h)

## Exercise 15.8

> Define static type and dynamic type.

- static type: Type with which a variable is defined or that an expression yields. Static type is known at **compile time**.

- dynamic type: Type of an object at **run time**. The dynamic type of an object to which a reference refers or to which a pointer points may differ from the static type of the reference or pointer.

## Exercise 15.9

> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

A pointer or reference to a base-class type can refer to an to object of derived type. In such cases the static type is reference (or pointer) to base, but the dynamic type is reference (or pointer) to derived.

Anything like this can be an example.

## Exercise 15.10

> Recalling the discussion from 8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` `read` function works.

the function takes a `istream` from which `ifstream` is derived. Hence the `ifstream` object "is a" `istream` ,which is why it works.

## Exercise 15.11

> Add a virtual `debug` function to your `Quote` class hierarchy
that displays the data members of the respective classes.

[Quote](ex15_11_Quote.h) | [Bulk_quote](ex15_11_Bulk_quote.h) | [Limit_quote](ex15_11_Limit_quote.h)

## Exercise 15.12

> Is it ever useful to declare a member function as both `override` and `final`? Why or why not?

Sure. `override` means overriding the same name virtual function in base class. `final` means preventing any overriding this virtual function by any derived classes that are more lower at the hierarchy. (@Mooophy)

## Exercise 15.13

> Given the following classes, explain each print function:

```cpp
class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) { print(os); os << " " << i; }
private:
    int i;
};
```

If there is a problem in this code, how would you fix it?

The `print` in `derived::print` wanted to call the `print` from the base class. However, the class scope `base::` was omitted. As a result, it will cause an infinite recursion.

**Fixed:**

```cpp
void print(ostream &os) { base::print(os); os << " " << i; }
```

## Exercise 15.14

> Given the classes from the previous exercise and the following objects, determine which function is called at run time:

```cpp
base bobj; base *bp1 = &bobj; base &br1 = bobj;
derived dobj; base *bp2 = &dobj; base &br2 = dobj;
(a) bobj.print();   // base::print()
(b) dobj.print();   // derived::print()
(c) bp1->name();    // base::name()
(d) bp2->name();    // base::name()
(e) br1.print();    // base::print()
(f) br2.print();    // derived::print()
```

e and f are called at run time.

## Exercise 15.15

> Define your own versions of `Disc_quote` and `Bulk_quote`.

[Disc_quote](ex15_15_Disc_quote.h) | [Bulk_quote](ex15_15_Bulk_quote.h)

## Exercise 15.16

> Rewrite the class representing a limited discount strategy, which you wrote for the exercises in 15.2.2 (p. 601), to inherit from `Disc_quote`.

[code](ex15_16_Limit_quote.h)

## Exercise 15.17

> Try to define an object of type Disc_quote and see what errors you get from the compiler.

```sh
note:   because the following virtual functions are pure within 'ch15::EX15::Disc_quote':
    virtual double net_price(size_t) const = 0;
                    ^
```

## Exercise 15.18

> Given the classes from page 612 and page 613, and assuming each object has the type specified in the comments, determine which of these assignments are legal. Explain why those that are illegal aren’t allowed:

```cpp
Base *p = &d1;  // d1 has type Pub_Derv     --  legal
p = &d2;        // d2 has type Priv_Derv    --  illegal
p = &d3;        // d3 has type Prot_Derv    --  illegal
p = &dd1;       // dd1 has type Derived_from_Public     --  legal
p = &dd2;       // dd2 has type Derived_from_Private    --  illegal
p = &dd3;       // dd3 has type Derived_from_Protected  --  illegal
```

-----

> **Assuming `D` inherits from `B`**:
>
> User code may use the derived-to-base conversion only if `D` inherits publicly from `B`. User code may not use the conversion if `D` inherits from `B` using either `protected` or `private`.

## Exercise 15.19

> Assume that each of the classes from page 612 and page 613 has a member function of the form:
>
>`void memfcn(Base &b) { b = *this; }`
>
> For each class, determine whether this function would be legal.

-----

> **Assuming `D` inherits from `B`**:
>
> Member functions and friends of `D` can use the conversion to `B` **regardless of how** `D` inherits from `B`. The derived-to-base conversion to a direct base class is **always accessible** to members and friends of a derived class.

Hence, the 3 below are all legal:

```cpp
Pub_Derv  d1; // legal
Priv_Derv d2; // legal
Prot_Derv d3; // legal
```

> Member functions and friends of classes derived from `D` may use the derived-to-base conversion if `D` inherits from `B` using **either `public` or `protected`**. Such code may not use the conversion if `D` inherits privately from `B`.

Hence:

```cpp
Derived_from_Public     dd1; // legal
Derived_from_Private    dd2; // illegal
Derived_from_Protected  dd3; // legal
```

## Exercise 15.20

> Write code to test your answers to the previous two exercises.

[code](ex15_20_Base.h)

## Exercise 15.21

> Choose one of the following general abstractions containing a family of types (or choose one of your own). Organize the types into an inheritance hierarchy:
- (a) Graphical file formats (such as gif, tiff, jpeg, bmp)
- (b) Geometric primitives (such as box, circle, sphere, cone)
- (c) C++ language types (such as class, function, member function)

(b): [code](ex15_21_GeomtricPrimitives.h)

## Exercise 15.22

> For the class you chose in the previous exercise, identify some of the likely virtual functions as well as public and protected members.

such as `shape_name()`, `resize_by_percentage(float pct)`, `area()`, `volume()`, etc.

## Exercise 15.23

> Assuming class `D1` on page 620 had intended to override its inherited `fcn` function, how would you fix that class? Assuming you fixed the class so that `fcn` matched the definition in `Base`, how would the calls in that section be resolved?

[Fixed](ex15_23.cpp)

## Exercise 15.24

> What kinds of classes need a virtual destructor? What operations must a virtual destructor perform?

Generally, a base class should define a virtual destructor.

The destructor needs to be virtual to allow objects in the inheritance hierarchy to be **dynamically allocated**.

## Exercise 15.25

> Why did we define a default constructor for `Disc_quote`? What effect, if any, would removing that constructor have on the behavior of `Bulk_quote`?

```cpp
#include <string>
using std::string;

class Quote {
public:
    Quote() = default;
    Quote(string const& b, double p) : bookNo(b), price(p) { }

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    //Disc_quote() = default;
    Disc_quote(string const& b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d){ }
    virtual double net_price(size_t) const = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(string const& book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) { }
    virtual double net_price(std::size_t cnt) const override {
        if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
};

int main()
{
    Bulk_quote b_quote;
}
```

Without it, when building the upper codes, the compiler would conplain that:

```sh
error: use of deleted function 'Bulk_quote::Bulk_quote()'
    Bulk_quote b_quote;
                ^
'Bulk_quote::Bulk_quote()' is implicitly deleted because the default definition would be ill-formed:
    Bulk_quote() = default;
    ^
```

The reason is that a constructor taking 4 parameters has been defined, which prevented the compiler generate synthesized version default constructor. As a result, the default constructor of any class derived from it has been defined as deleted. Thus the default constructor must be defined explicitly so that the derived classes can call it when executing its default constructor.

## Exercise 15.26

> Define the `Quote` and `Bulk_quote` copy-control members to do the same job as the synthesized versions. Give them and the other constructors print statements that identify which function is running. Write programs using these classes and predict what objects will be created and destroyed. Compare your predictions with the output and continue experimenting until your predictions are reliably correct.

- [Quote](ex15_26_Quote.h)
- [Bulk_quote](ex15_26_Bulk_quote.h)

## Exercise 15.27

> Redefine your `Bulk_quote` class to inherit its constructors.

[code](ex15_27_Bulk_quote.h)

## Exercise 15.28

> Define a `vector` to hold `Quote` objects but put `Bulk_quote` objects into that `vector`. Compute the total `net_price` of all the elements in the `vector`.

```cpp
#include <vector>
#include <numeric>
#include "ex15_27_Bulk_quote.h"

int main()
{
    std::vector<Quote> vecQuote;

    Bulk_quote bulk0("0-201-82470-1", 50, 5, 0.2);
    Bulk_quote bulk1("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    std::cout << "bulk_quote's total: " << bulk0.net_price(5) + bulk1.net_price(5) << std::endl;

    vecQuote.push_back(bulk0);
    vecQuote.push_back(bulk1);

    double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(),0.0, [](double ret, const Quote &obj){
        return ret += obj.net_price(5);
    });

    // total price in the vector.
    std::cout << "total in the vector: " << total << std::endl;
}
```

**Output:**

```sh
bulk_quote's total: 325
total in the vector: 500
```

## Exercise 15.29

> Repeat your program, but this time store `shared_ptrs` to objects of type `Quote`. Explain any discrepancy in the sum generated by the this version and the previous program. If there is no discrepancy, explain why there isn’t one.

```cpp
#include <vector>
#include <numeric>
#include <memory>

#include "ex15_27_Bulk_quote.h"

int main()
{
    std::vector<std::shared_ptr<Quote>> vecQuote;

    std::shared_ptr<Bulk_quote> spBulk0 = std::make_shared<Bulk_quote>("0-201-82470-1", 50, 5, 0.2);
    std::shared_ptr<Bulk_quote> spBulk1 = std::make_shared<Bulk_quote>("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    std::cout << "bulk_quote's total: " << spBulk0->net_price(5) + spBulk1->net_price(5) << std::endl;

    vecQuote.push_back(spBulk0);
    vecQuote.push_back(spBulk1);

    double total = std::accumulate(vecQuote.cbegin(), vecQuote.cend(),0.0, [](double ret, std::shared_ptr<Quote> sp){
        return ret += sp->net_price(5);
    });

    // total price in the vector.
    std::cout << "total in the vector: " << total << std::endl;
}
```

**Output:**

```sh
bulk_quote's total: 325
total in the vector: 325
```

Because derived objects are "sliced down" when assigned to a base-type object. Thus, when put `Bulk_quote` object into the `vector` of `Quote`, all the object "slice down" to `Quote`.

If we want to holds objects related by inheritance, we should define the `vector` to hold pointers(preferable smart pointers) to the base class. So, the `vector` contains are dynamic type of the objects.

Different from previous program, it can be found that 20% and 50% discount has been applied to the total price calculation.

## Exercise 15.30

> Write your own version of the `Basket` class and use it to compute prices for the same transactions as you used in the previous exercises.

- [Basket](ex15_30_Basket.h)
- [Quote & Bulk_quote](ex15_30_Quote_Bulk_quote.h)

## Exercise 15.31

> Given that `s1`, `s2`, `s3`, and `s4` are all `string`s, determine what objects are created in the following expressions:
- (a) `Query(s1) | Query(s2) & ~ Query(s3);`
- (b) `Query(s1) | (Query(s2) & ~ Query(s3));`
- (c) `(Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)));`

- (a): `WordQuery` -> `NotQuery` -> `AndQuery` -> `OrQuery`
- (b): `WordQuery` -> `NotQuery` -> `AndQuery` -> `OrQuery` (same as the previous one)
- (c): `WordQuery` -> `AndQuery` -> `OrQuery`

## Exercise 15.32

> What happens when an object of type `Query` is copied, moved, assigned, and destroyed?

- **copy**: While being copied, the synthesized copy constructor is called. It copies the data member into the new object. Since in this case, the data member is a shared pointer, while copying, the corresponding shared pointer points to the same address and the use count from the both shared pointer becomes 2.

- **move**: while being moved, the synthesized move constructor is called. It moves the data member into the new object. In this case, the shared pointer from the newly created object will point to the address to which the original shared pointer pointed. After the move operation, the use count of the shared pointer in the new object is 1, whereas the pointer from the original object becomes `nullptr`.

- **copy assignment**: The synthesized copy assignment will be called. The outcome of this operation is identical with the copy operation.

- **move assignment**: The synthesized move assignment will be called. The rest is the same as the move operation.

- **destroy**: The synthesized destructor will be called. It will call the destructor of `shared_ptr` which decrements the use count. If the count becomes zero, the destructor from `shared_ptr` will delete the resources it point to.

## Exercise 15.33

> What about objects of type `Query_base`?

Managed by the synthesized version. Since `Query_base` a abstract class, the object of this type is essentially a sub-object of its derived class.
