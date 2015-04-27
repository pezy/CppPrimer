# Chapter 15. Object-Oriented Programming

## Exercise 15.1:
> What is a virtual member?

A member function should be dynamically bound by preceding its declaration.

A virtual member in a base class expects its derived class define its own version. In particular base classes ordinarily should define a virtual destructor, even if it does no work.

## Exercise 15.2:
> How does the `protected` access specifier differ from `private`?

base class members:
- `private:`: base class itself and friends can access
- `protected`: base class itself, friends and derived classes can access

## Exercise 15.3:
> Define your own versions of the `Quote` class and the `print_total` function.

[code](ex15_03_Quote.h)

## Exercise 15.4:
> Which of the following declarations, if any, are incorrect? Explain why.
```cpp
class Base { ... };
(a) class Derived : public Derived { ... };
(b) class Derived : private Base { ... };
(c) class Derived : public Base;
```

- (a) incorrect, derive from itself
- (b) incorrect, this is a definition not a declaration
- (c) incorrect, A derived class is declared like any other class. The declaration contains the class name but does not include its derivation list

## Exercise 15.5:
> Define your own version of the `Bulk_quote` class.

[code](ex15_05_Bulk_quote.h)

## Exercise 15.6:
> Test your `print_total` function from the exercises in 15.2.1 (p. 595) by passing both `Quote` and `Bulk_quote` objects o that function.

[TEST](TEST.cpp)

## Exercise 15.7:
> Define a class that implements a limited discount strategy, which applies a discount to books purchased up to a given limit. If the number of copies exceeds that limit, the normal price applies to those purchased beyond the limit.

[code](ex15_07_Limit_quote.h)

## Exercise 15.8:
> Define static type and dynamic type.

- static type: Type with which a variable is defined or that an expression yields. Static type is known at **compile time**.

- dynamic type: Type of an object at **run time**. The dynamic type of an object to which a reference refers or to which a pointer points may differ from the static type of the reference or pointer.

## Exercise 15.9:
> When is it possible for an expression’s static type to differ from its dynamic type? Give three examples in which the static and dynamic type differ.

A pointer or reference to a base-class type can refer to an to object of derived type. In such cases the static type is reference (or pointer) to base, but the dynamic type is reference (or pointer) to derived.

Anything like this can be an example.

## Exercise 15.10:
> Recalling the discussion from 8.1 (p. 311), explain how the program on page 317 that passed an `ifstream` to the `Sales_data` `read` function works.

the function takes a `istream` from which `ifstream` is derived. Hence the `ifstream` object "is a" `istream` ,which is why it works.

## Exercise 15.11:
> Add a virtual `debug` function to your `Quote` class hierarchy
that displays the data members of the respective classes.

[Quote](ex15_11_Quote.h) | [Bulk_quote](ex15_11_Bulk_quote.h) | [Limit_quote](ex15_11_Limit_quote.h)

## Exercise 15.12:
> Is it ever useful to declare a member function as both `override` and `final`? Why or why not?

Sure. `override` means overriding the same name virtual function in base class. `final` means preventing any overriding this virtual function by any derived classes that are more lower at the hierarchy. (@Mooophy)

## Exercise 15.13:
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

## Exercise 15.14:
> Given the classes from the previous exercise and the following objects, determine which function is called at run time:
```cpp
base bobj; base *bp1 = &bobj; base &br1 = bobj;
derived dobj; base *bp2 = &dobj; base &br2 = dobj;
(a) bobj.print();   // base::print()
(b) dobj.print();   // derived::print()
(c) bp1->name();    // base::name()
(d) bp2->name();    // derived::name()
(e) br1.print();    // base::print()
(f) br2.print();    // derived::print()
```

e and f are called at run time.

## Exercise 15.15:
> Define your own versions of `Disc_quote` and `Bulk_quote`.

[Disc_quote](ex15_15_Disc_quote.h) | [Bulk_quote](ex15_15_Bulk_quote.h)

## Exercise 15.16:
> Rewrite the class representing a limited discount strategy, which you wrote for the exercises in 15.2.2 (p. 601), to inherit from `Disc_quote`.

[code](ex15_16_Limit_quote.h)

## Exercise 15.17:
> Try to define an object of type Disc_quote and see what errors you get from the compiler.

```sh
note:   because the following virtual functions are pure within 'ch15::EX15::Disc_quote':
    virtual double net_price(size_t) const = 0;
                    ^
```
