#include "dijkstra.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("dijkstra base case") {
  AirportGraph graph;
  Airport a("Kugaaruk Airport", "1", 1.0, 1.0);
  Airport b("Baie Comeau Airport", "2", 2.0, 2.0);
  Airport c("CFB Bagotville", "3", 3.0, 3.0);
  Airport d("Baker Lake Airport", "4", 4.0, 4.0);
  graph.insertAirport(a);
  graph.insertAirport(b);
  graph.insertAirport(c);
  graph.insertAirline(a, b, 10, "1");
  graph.insertAirline(a, c, 100, "2");
  graph.insertAirline(b, c, 10, "4");
  Dijkstra dijk(graph, a);
  vector<Airport> result;
  result.push_back(a);
  result.push_back(b);
  result.push_back(c);

  REQUIRE(dijk.shortestPath(c) == result);
}