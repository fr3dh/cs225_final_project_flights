#include "dijkstra.h"
#include <catch2/catch_test_macros.hpp>
using namespace std;

TEST_CASE("dijkstra base case", "[dijkstra]") {
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

TEST_CASE("dijkstra 4", "[dijkstra]") {
  AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");

 

  Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
  Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
  Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
  Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);

  Dijkstra dijk(graph, kug);
  vector<Airport> shortest = dijk.shortestPath(baker);
  vector<Airport> check;
  check.push_back(kug);
  check.push_back(cfb);
  check.push_back(baker);
  REQUIRE(shortest == check);
}

TEST_CASE("dijkstra 50" , " [dijkstra]") {
  AirportGraph graph = AirportGraph("../tests/airports50.csv", "../tests/airlines50.csv");

  Airport kazan = Airport("Kazan International Airport", "2990", 55.6062, 49.2787);
    
  Airport baelgorod = Airport("Belgorod International Airport", "6156", 50.6438, 36.5901);

  Dijkstra dijk(graph, kazan);
  vector<Airport> shortest = dijk.shortestPath(baelgorod);

  vector<Airport> check;
  check.push_back(kazan);
  check.push_back(baelgorod);
  REQUIRE(shortest == check);
}

// TEST_CASE("dijkstra 500", "[dijkstra]") {
//   AirportGraph graph = AirportGraph("../tests/airports500.csv", "../tests/routes500.csv");
//   map<Airport, map<Airport,Airline>> map = graph.getMap();
//   cout << map.size() << endl;
 
//   Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
//   Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

//   Dijkstra dijk(graph, ohare);
//   vector<Airport> shortest = dijk.shortestPath(hk);

//   cout << shortest.size() << endl;
// }

