#include <iostream>
#include <bitset>
#include <cassert>

int main()
{
    // init from the sequence: 1, 2, 3, 5, 8, 13, 21
    std::bitset<22> bitseq("1000000010000100101110");
    std::cout << bitseq << std::endl;

    // Default initialize, then turn on.
    std::bitset<22> bit_default;
    for (auto i : {1, 2, 3, 5, 8, 13, 21})
        bit_default.set(i);
    std::cout << bit_default << std::endl;

    assert(bitseq == bit_default);
}