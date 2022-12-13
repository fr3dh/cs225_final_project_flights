#include <catch2/catch_test_macros.hpp>

#include "airport.h"
#include "airline.h"
#include "airportgraph.h"
#include "bfs.h"
#include "visualization.h"
using namespace std;


TEST_CASE("BFS TRAVERSAL", "[bfs]") {
    AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    
    string file = "bfs4.gif";
    BFS b("../tests/airport.csv", "../tests/airline.csv", graph);
    b.play(file);
    map<Airport, bool> visited = b.getVisited();

    //check all the airports is visited
    for (auto it : visited) {
        REQUIRE(it.second == true);
    }
}

TEST_CASE("BFS TRAVERSAL2", "[bfs]") {
    AirportGraph graph = AirportGraph("../tests/airport1.csv", "../tests/airline1.csv");

    
    string file = "bfs7.gif";
    BFS b("../tests/airport1.csv", "../tests/airline1.csv", graph);
    b.play(file);
     map<Airport, bool> visited = b.getVisited();
     //check all the airports is visited
    for (auto it : visited) {
        REQUIRE(it.second == true);
    }

}

TEST_CASE("BFS TRAVERSAL50", "[bfs]") {
    AirportGraph graph = AirportGraph("../tests/airports50.csv", "../tests/airlines50.csv");

    
    string file = "bfs50.gif";
    BFS b("../tests/airports50.csv", "../tests/airlines50.csv", graph);
    b.play(file);
    map<Airport, bool> visited = b.getVisited();
    //check all the airports is visited
    for (auto it : visited) {
        REQUIRE(it.second == true);
    }

}