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
