#pragma push_macro("_SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING")
#define _SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#undef _SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING
#pragma pop_macro("_SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING")

#include "bst.hpp"

TEST_CASE("Can create empty bst", "[ctor]") {
	binary_search_tree<int> bstint;

	REQUIRE(bstint.size() == 0);
}

TEST_CASE("inserting to bst works", "[insert]") {
	binary_search_tree<int> bstint;
	
	const auto [index, inserted] = bstint.insert(5);
	REQUIRE(index == 0);
	REQUIRE(inserted == true);
	REQUIRE(bstint.size() == 1);

	SECTION("Inserting before works")
	{
		const auto[index, inserted] = bstint.insert(4);
		REQUIRE(index == 1); // I don't expect it to move the root
		REQUIRE(inserted == true);
		REQUIRE(bstint.size() == 2);
	}

	SECTION("Inserting after works")
	{
		const auto[index, inserted] = bstint.insert(6);
		REQUIRE(index == 1); // I don't expect it to move the root
		REQUIRE(inserted == true);
		REQUIRE(bstint.size() == 2);
	}

	SECTION("Inserting already existing is equivalent to finding")
	{
		const auto[index, inserted] = bstint.insert(5);
		REQUIRE(index == 0);
		REQUIRE(inserted == false);
		REQUIRE(bstint.size() == 1);
	}
}
