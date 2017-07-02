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

I prefer the tuple version, because this version is more flexible.

## Exercise 17.8

> What would happen if we passed `Sales_data()` as the third parameter to accumulate in the last code example in this section?

Nothing happened, it's the same as passed `Sales_data(s)`.
Because `std::accumulate`'s third parameter is the initial value of the sum. It's will be zero whether `Sales_data()` or `Sales_data(s)`. Check the constructor of `Sales_data` and the `operator+=` member for more information.

## Exercise 17.9

>Explain the bit pattern each of the following `bitset` objects contains:

```cpp
(a) bitset<64> bitvec(32);
(b) bitset<32> bv(1010101);
(c) string bstr; cin >> bstr; bitset<8> bv(bstr);
```

(a): 64 bits, lower-order 6 bits are `100000`, remaining bits are 0.
(b): 00000000000011110110100110110101
(c): depends on what user has been input.

## Exercise 17.10

> Using the sequence 1, 2, 3, 5, 8, 13, 21, initialize a `bitset` that has a 1 bit in each position corresponding to a number in this sequence. Default initialize another `bitset` and write a small program to turn on each of the appropriate bits.

[`bitset` initialization and turn on test](ex17_10.cpp)

## Exercise 17.11

> Define a data structure that contains an integral object to track responses to a true/false quiz containing 10 questions. What changes, if any, would you need to make in your data structure if the quiz had 100 questions?

[`QuizResponses` Definition](ex17_11_quiz_responses.h)

## Exercise 17.12

> Using the data structure from the previous question, write a function that takes a question number and a value to indicate a true/false answer and updates the quiz results accordingly.

[`QuizResponses` Definition](ex17_11_quiz_responses.h)

## Exercise 17.13

> Write an integral object that contains the correct answers for the true/false quiz. Use it to generate grades on the quiz for the data structure from the previous two exercises.

[Test `QuizResponses` class](ex17_11_quiz_responses_test.cpp)

## Exercise 17.14

> Write several regular expressions designed to trigger various errors. Run your program to see what output your compiler generates for each error.

[Try error code 1](ex17_14.cpp)

## Exercise 17.15

> Write a program using the pattern that finds words that violate the “i before e except after c” rule. Have your program prompt the user to supply a word and indicate whether the word is okay or not. Test your program with words that do and do not violate the rule.

[I before E except after C rule](ex17_15.cpp)

## Exercise 17.16

> What would happen if your regex object in the previous program were initialized with "[^c]ei"? Test your program using that pattern to see whether your expectations were correct.

`[^c]ei` says we want any such letter that is followed by the letters 'ei', This pattern describes strings containing exactly **three** characters. The test words in [ex17_15](ex17_15.cpp) will all fail.