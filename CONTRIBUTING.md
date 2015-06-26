# Contributing to CppPrimer

Please ensure your pull request adheres to the following guidelines:

1. No tabs, Use only spaces, and indent **4 space** at a time.
2. No `using namespace std;`
3. Put **spaces** after each **semicolon**, around **operators**.
```cpp
for(auto i=0;i!=size;++i) 		     // Bad
for (auto i = 0; i != size; ++i) 	  // Good
auto epsilon=2*gamma-delta*pi;	     // Bad
auto epsilon = 2 * gamma - delta * pi; // Good
```
4. Put **braces** to next line in function(such as `main()`), **otherwise, End of line**.
```cpp
int main()
{
    Sales_item total;
    if (std::cin >> total) {
        Sales_item trans;
        while (std::cin >> trans) {
            //...
        }
    }
}
```

If you intall **[ClangFormat](http://clang.llvm.org/docs/ClangFormat.html)**, You wouldn't care about the format, just run the command:
```sh
clang-format -i your-code.cpp
```

#### Tips for good commits and issues.

1. Read up on [Github Flavored Markdown](https://help.github.com/articles/github-flavored-markdown)
2. [Closing Issues via Commit Messages](https://github.com/tiimgreen/github-cheat-sheet#closing-issues-via-commit-messages) is encouraged.
