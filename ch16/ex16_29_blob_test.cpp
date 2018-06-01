#include "ex16_24_blob.h"
#include <iostream>
#include <string>

int main()
{
    Blob<std::string> sb1{"a", "b", "c"};
    Blob<std::string> sb2 = sb1;

    sb2[2] = "b";

    if (sb1 > sb2) {
        for (auto iter = sb2.cbegin(); iter != sb2.cend(); ++iter) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }

    ConstBlobPtr<std::string> iter(sb2);
    std::cout << iter->size() << std::endl;

    std::vector<std::string> vec{"good", "for", "you"};
    Blob<std::string> sb3(vec.begin(), vec.end());

    for (auto&& s : sb3) {
        std::cout << s << " ";
    }
    std::cout << "\n";
}
