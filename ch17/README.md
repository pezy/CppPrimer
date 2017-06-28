# Chapter 17. Specialized Library Facilities

## Exercise 17.1

> Define a `tuple` that holds three `int` values and initialize the members to 10, 20, and 30

```cpp
tuple<int, int, int> threeInt(10, 20, 30);
```

## Exercise 17.2

> Define a `tuple` that holds a `string`, a `vector<string>`, and a `pair<string, int>`.

```cpp
tuple<std::string, std::vector<std::string>, std::pair<std::string, int> t;
```

## Exercise 17.3

> Rewrite the `TextQuery` programs from 12.3 (p. 484) to use a `tuple` instead of the `QueryResult` class.
Explain which design you think is better and why.

[TextQuery Definition](ex17_03_text_query.h) | [TextQuery Implementation](ex17_03_text_query.cpp) | [TextQuery Test](ex17_03_text_query_test.cpp)

## Exercise 17.4

> Write and test your own version of the `findBook` function.

[`findBook` function by tuple way](ex17_04_findBook.h) | [`findBook` Test](ex17_findBook_test.cpp)

## Exercise 17.5

> Rewrite `findBook` to return a pair that holds an index and a pair of iterators.

[`findBook` function by pair way](ex17_05_findBook.h) | [`findBook` Test](ex17_findBook_test.cpp)

## Exercise 17.6

> Rewrite `findBook` so that it does not use tuple or pair.

[`findBook` function without tuple or pair](ex17_06_findBook.h) | [`findBook` Test](ex17_findBook_test.cpp)

## Exercise 17.7

> Explain which version of `findBook` you prefer and why.

I prefer the tuple version, because this version is the most refined.

## Exercise 17.8

> What would happen if we passed `Sales_data()` as the third parameter to accumulate in the last code example in this section?

Nothing happened, it's the same as passed `Sales_data(s)`.
Because `std::accumulate`'s third parameter is the initial value of the sum. It's will be zero whether `Sales_data()` or `Sales_data(s)`. Check the constructor of `Sales_data` and the `operator+=` member for more information.