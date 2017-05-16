# Chapter 1. Getting Started

## Exercise 1.1

> Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.

- Windows

![windows](https://cloud.githubusercontent.com/assets/1147451/8334465/a87e3528-1aca-11e5-877d-c610f087fc40.png)

- Linux

![Linux](https://cloud.githubusercontent.com/assets/1147451/8334480/c160e75c-1aca-11e5-92d5-7d0a05fbf493.png)

## Exercise 1.2

> Exercise 1.2: Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.

- Windows

![image](https://cloud.githubusercontent.com/assets/1147451/8335952/72179d5e-1ad3-11e5-84ff-e924816e64a3.png)

- Linux

![image](https://cloud.githubusercontent.com/assets/1147451/8335963/8debbc5e-1ad3-11e5-9761-013139d291d8.png)

**255**? why? check [this](http://www.tldp.org/LDP/abs/html/exitcodes.html)

## Exercise 1.3

> Write a program to print Hello, World on the standard output.

```cpp
#include <iostream>

int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

## Exercise 1.4

> Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, *, to print the product instead.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
    return 0;
}
```

## Exercise 1.5

> We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
    return 0;
}
```

## Exercise 1.6

> Explain whether the following program fragment is legal.

It's illegal.

**`[Error] expected primary-expression before '<<' token`**

Fixed it: remove the spare semicolons.

```cpp
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

## Exercise 1.7

> Compile a program that has incorrectly nested comments.

Example:

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
  return 0;
}
```

Compiled result(g++):

![ex1_7](https://cloud.githubusercontent.com/assets/1147451/8334581/4fb4a408-1acb-11e5-98e3-54c0929198ec.png)

## Exercise 1.8

> Indicate which, if any, of the following output statements are legal:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

> After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.

Compiled result(g++):

![ex1_8](https://cloud.githubusercontent.com/assets/1147451/8334603/6aa321e0-1acb-11e5-988a-57e87a53b141.png)

Corrected? just added a quote:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```

Output:

```sh
    /**/ */ /*
```

## [Exercise 1.9](ex1_09.cpp)

## [Exercise 1.10](ex1_10.cpp)

## [Exercise 1.11](ex1_11.cpp)

## Exercise 1.12

> What does the following for loop do? What is the final value of sum?

```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
    sum += i;
```

the loop sums the numbers from -100 to 100. the final value of sum is zero.

## Exercise 1.13

> Rewrite the exercises from 1.4.1 (p. 13) using for loops.

**Ex1.9**:

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;

    std::cout << "the sum is: " << sum << std::endl;

    return 0;
}
```

**Ex1.10**:

```cpp
#include <iostream>

int main()
{
    for (int i = 10; i >= 0; --i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

**Ex1.11**:

```cpp
#include <iostream>

int main()
{
    int small = 0, big = 0;
    std::cout << "please input two integers:";
    std::cin >> small >> big;

    if (small > big) {
        int tmp = small;
        small = big;
        big = tmp;
    }

    for (int i = small; i <= big; ++i)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
```

## Exercise 1.14

> Compare and contrast the loops that used a `for` with those using a `while`. Are there advantages or disadvantages to using either form?

- Advantage of `for` and disadvantage of `while`:
    - Locality, the variable in the scope of the loop.
    - Pattern happens so often: using a variable in a condition and incrementing that variable in the body.
- Advantage of `while` and disadvantage of `for`:
    - Clear when there is only one static condition.
    - Readable when the global variables incremented in the body.

-----

[A similar question on Stack Overflow](http://stackoverflow.com/questions/2950931/for-vs-while-in-c-programming)

## Exercise 1.15

> Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.

Self-training.

## Exercise 1.16

> Write your own version of a program that prints the sum of a set of integers read from `cin`.

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int value = 0; std::cin >> value; )
        sum += value;
    std::cout << sum << std::endl;
    return 0;
}
```

## Exercise 1.17

> What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If all equal, the count will be printed out. If there are no duplicated values, A new line will be printed when `Enter` clicked.

## Exercise 1.18

> Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

![ex1_18](https://cloud.githubusercontent.com/assets/1147451/8335404/0861c478-1ad0-11e5-8083-c05a0cd9e758.png)

## Exercise 1.19

> Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

check [ex1_11.cpp](https://github.com/pezy/Cpp-Primer/blob/master/ch01/ex1_11.cpp)

## Exercise 1.20

> <http://www.informit.com/title/032174113> contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.

check [code](ex1_20.cpp).

Test it using the `data`/`book.txt`:

![ex1_20](https://cloud.githubusercontent.com/assets/1147451/8335638/8f5c2bca-1ad1-11e5-9c51-288382710df2.png)

## Exercise 1.21

> Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

The program should check whether the objects have the same ISBN.(check 1.5.2)

[Code](ex1_21.cpp)

## Exercise 1.22

> Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.

Tip: this program will appear in the section 1.6.

[Code](ex1_22.cpp).

![ex1_22](https://cloud.githubusercontent.com/assets/1147451/8335700/d85ee22c-1ad1-11e5-9612-1155145606c1.png)

## Exercise 1.23

> Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

Tip: please review the `1.4.4`.

[Code](ex1_23.cpp).

## Exercise 1.24

> Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.

`data`/`book.txt` may be used as the records.

![ex1_24](https://cloud.githubusercontent.com/assets/1147451/8335734/0fbefbbc-1ad2-11e5-9df3-fa1203dffb42.png)

## Exercise 1.25

> Using the `Sales_item.h` header from the Web site, compile and execute the bookstore program presented in this section.

![ex1_25](https://cloud.githubusercontent.com/assets/1147451/8335742/1efb475c-1ad2-11e5-9484-69ae44b79385.png)
