#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "prime.h"

TEST_CASE("basic prime functionality", "[number]") {
  typedef prime<int> prime;

  SECTION("known small primes") {
    REQUIRE(!prime::is_prime(1));
    REQUIRE(prime::is_prime(2));
    REQUIRE(prime::is_prime(3));
    REQUIRE(!prime::is_prime(4));
    REQUIRE(prime::is_prime(5));
    REQUIRE(prime::is_prime(7));
    REQUIRE(!prime::is_prime(9));
  }

  SECTION("precompute in large range") {
    prime::pre_compute(1000000);
    REQUIRE(prime::is_prime(99991));
    REQUIRE(!prime::is_prime(99990));
    REQUIRE(prime::is_prime(57859));
    REQUIRE(prime::is_prime(48079));
    REQUIRE(!prime::is_prime(999999));
  }

}
