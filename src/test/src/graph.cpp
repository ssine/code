#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.h"
#include "digraph.h"

TEST_CASE("graph nodes and edges can be added and deleted", "[graph]") {
  graph<int> g;

  SECTION("add edges and get them") {
    g.add_vertex(1);
    g.add_vertex(3);
    g.add_vertex(5);
    g.add_edge(1, 5, 10);

    REQUIRE(g.have_edge(1, 5));
    REQUIRE(g.get_edge(1, 5) == 10);
  }
  SECTION("test nonexist edges") {
    g.add_vertex(1);
    g.add_vertex(3);

    REQUIRE(!g.get_edge_optional(1, 3));
  }
}

TEST_CASE("retrieve adjacent nodes", "[graph]") {
  graph<int> g;
  g.add_vertex(1);
  g.add_vertex(3);
  g.add_vertex(5);
  g.add_vertex(7);
  g.add_vertex(9);
  g.add_vertex(10);
  g.add_edge(1, 3);
  g.add_edge(1, 5);
  g.add_edge(1, 7);
  g.add_edge(1, 9);

  SECTION("degree number") {
    REQUIRE(g.degree(1) == 4);
    REQUIRE(g.degree(3) == 1);
    REQUIRE(g.degree(5) == 1);
    REQUIRE(g.degree(7) == 1);
    REQUIRE(g.degree(9) == 1);
    REQUIRE(g.degree(10) == 0);
  }

  SECTION("access using iterator") {
    auto& vtcs = g.get_adjacent_vertices(1);
    int i = 3;
    for (auto& it : vtcs) {
      REQUIRE(it == i);
      i += 2;
    }
  }

  SECTION("access using subscription") {
    auto& vtcs = g.get_adjacent_vertices(1);
    REQUIRE(vtcs[0] == 3);
    REQUIRE(vtcs[1] == 5);
    REQUIRE(vtcs[2] == 7);
    REQUIRE(vtcs[3] == 9);
    REQUIRE(g.get_adjacent_vertices(3)[0] == 1);
    REQUIRE(g.get_adjacent_vertices(5)[0] == 1);
    REQUIRE(g.get_adjacent_vertices(7)[0] == 1);
    REQUIRE(g.get_adjacent_vertices(9)[0] == 1);
  }

  SECTION("find max clique") {
    g.add_edge(3, 5);
    auto clique = g.find_max_clique();
    REQUIRE(clique.count(1) == 1);
    REQUIRE(clique.count(3) == 1);
    REQUIRE(clique.count(5) == 1);
  }
}

TEST_CASE("directed graph", "[graph]") {
  digraph<int> g;
  g.add_vertex(1);
  g.add_vertex(3);
  g.add_vertex(5);
  g.add_vertex(7);
  g.add_vertex(9);
  g.add_vertex(10);
  g.add_edge(1, 3);
  g.add_edge(1, 5);
  g.add_edge(1, 7);
  g.add_edge(1, 9);

  SECTION("degree number") {
    REQUIRE(g.degree(1) == 4);
    REQUIRE(g.degree(3) == 0);
    REQUIRE(g.degree(5) == 0);
    REQUIRE(g.degree(7) == 0);
    REQUIRE(g.degree(9) == 0);
    REQUIRE(g.degree(10) == 0);
  }
}
