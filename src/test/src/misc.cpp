#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "misc.h"
#include <string>
using namespace std;

TEST_CASE("find substring", "[misc]") {
  SECTION("simple") {
    REQUIRE(findSubstringPosition("abcdefg", "def") == 3);
    REQUIRE(findSubstringPosition("abcdefg", "abcdefg") == 0);
    REQUIRE(findSubstringPosition("abcdefg", "g") == 6);
    REQUIRE(findSubstringPosition("abcdefg", "h") == -1);
    REQUIRE(findSubstringPosition("abcdefg", "defgh") == -1);
    REQUIRE(findSubstringPosition("", "h") == -1);
  }

}

