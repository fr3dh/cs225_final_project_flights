#include "dijkstra.h"
#include <catch2/catch_test_macros.hpp>

Airport a("Kugaaruk Airport", "1", 1.0, 1.0);
Airport b("Baie Comeau Airport", "2", 2.0, 2.0);
Airport c("CFB Bagotville", "3", 3.0, 3.0);
Airport d("Baker Lake Airport", "4", 4.0, 4.0);
Airline ab(a, b, 100, "1");
Airline ac(a, c, 100, "2");
Airline ad(a, d, 100, "3");
Airline bc(b, c, 100, "4");

TEST_CASE("airport base case") {
  AirportGraph graph;
  graph.insertAirport(a);
  graph.insertAirport(b);
  graph.insertAirport(c);
  REQUIRE(graph.airportExists(a) == true);
  REQUIRE(graph.airportExists(b) == true);
  REQUIRE(graph.airportExists(c) == true);
  REQUIRE(graph.airportExists(d) == false);
}

TEST_CASE("airline base case") {
  AirportGraph graph;
  graph.insertAirline(a, b, 100, "1");
  graph.insertAirline(a, c, 100, "2");
  graph.insertAirline(b, c, 100, "4");
  REQUIRE(graph.airlineExists(a,b) == true);
  REQUIRE(graph.airlineExists(a,c) == true);
  REQUIRE(graph.airlineExists(b,c) == true);
}