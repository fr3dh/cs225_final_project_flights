#include <catch2/catch_test_macros.hpp>

#include "airport.h"
#include "airline.h"
#include "airportgraph.h"
using namespace std;


TEST_CASE("BFS TRAVERSAL", "[bfs]") {
    AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    REQUIRE(graph.BFS() == 4);
}

TEST_CASE("BFS TRAVERSAL2", "[bfs]") {
    AirportGraph graph = AirportGraph("../tests/airport1.csv", "../tests/airline1.csv");
     map<Airport, map<Airport, Airline>> map = graph.getMap();
   for (auto it : map) {
        Airport here = it.first;
        cout << "source: " <<  here.name << " -> ";
        for (auto i : it.second) {
            Airport th = i.first;
            Airline t = i.second;
            cout << "dest airport: " << th.name << " : ";
            cout << "airline id: " << t.label << " |||  ";
        }
        cout << endl;
   }
    REQUIRE(graph.BFS() == 7);
}