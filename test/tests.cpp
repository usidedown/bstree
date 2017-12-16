#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "bst.hpp"

TEST_CASE("Can create empty bst", "[bst]") {
	binary_search_tree<int> bstint;

	REQUIRE(bstint.size() == 0);
}
