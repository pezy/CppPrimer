//! @file   Exercise 9.28
//! @author pezy
//! @date   2017-04-24
//! @Brief  Write a function that takes a forward_list and two additional string arguments. 
//!			The function should find the first string and insert the second immediately following the first. 
//!			If the first string is not found, then insert the second string at the end of the list.

#include <forward_list>
#include <string>

#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"

using std::forward_list;
using std::string;

void find_and_insert(forward_list<string> &list, const string& to_find, const string& to_add)
{
	auto prev = list.before_begin();
	auto size = std::distance(list.begin(), list.end());
	for (auto curr = list.begin(); curr != list.end(); prev = curr++)
		if (*curr == to_find) curr=list.insert_after(curr, to_add);
	if (size == std::distance(list.begin(), list.end())) list.insert_after(prev, to_add);
}

TEST_CASE("common", "[find_and_insert]") {
	forward_list<string> l{ "a", "b", "c", "d", "e", "f" };
	forward_list<string> r{ "a", "b", "c", "g", "d", "e", "f" };
	find_and_insert(l, "c", "g");
	REQUIRE(l == r);
}

TEST_CASE("not found", "[find_and_insert]") {
	forward_list<string> l{ "a", "b", "c", "d", "e", "f" };
	forward_list<string> r{ "a", "b", "c", "d", "e", "f", "g" };
	find_and_insert(l, "g", "g");
	REQUIRE(l == r);
}

TEST_CASE("multi found", "[find_and_insert]") {
	forward_list<string> l{ "a", "b", "c", "d", "b", "f" };
	forward_list<string> r{ "a", "b", "g", "c", "d", "b", "g", "f" };
	find_and_insert(l, "b", "g");
	REQUIRE(l == r);
}
