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
