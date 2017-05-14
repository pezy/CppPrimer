//
//  ex11_31.cpp
//  Exercise 11.31
//
//  Created by pezy on 12/17/14.
//  Copyright (c) 2014 pezy. All rights reserved.
//
//  Write a program that defines a multimap of authors and their works.
//  Use **find** to find **an element** in the multimap and erase that element.
//  Be sure your program works correctly if the element you look for is not in
//  the map.

#include <iostream>
#include <map>
#include <string>

using std::string;

int main()
{
    std::multimap<string, string> authors{
        {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
        {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"},
        {"pezy", "CP5"}};
    // want to delete an element that author is [pezy], work is [CP5].
    string author = "pezy";
    string work = "CP5";

    for (auto found = authors.find(author);
         found != authors.end() && found->first == author;) {
        if (found->second == work)
            found = authors.erase(found);
        else
            ++found;
    }

    for (const auto& author : authors)
        std::cout << author.first << " " << author.second << std::endl;
}
