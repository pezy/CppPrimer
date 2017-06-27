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