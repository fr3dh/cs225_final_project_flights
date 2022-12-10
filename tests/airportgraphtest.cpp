#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;
#include "airportgraph.h"
#include "airport.h"


TEST_CASE("airportgraph test airportexist", "[graph]") {
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
     Airport wrong = Airport("B", "4", 34.342, 34.341);
    graph.insertAirport(kug);
    REQUIRE(graph.airportExists(kug) == true);
    REQUIRE(graph.airportExists(wrong) == false);
}
TEST_CASE("airportgraph test airline exist", "[graph]") {
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    
    Airline  b = Airline(kug, baie, 1, "2B");
    Airport wrong = Airport("B", "4", 34.342, 34.341);
    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirline(kug, baie, 1, "2B");
    
    
    REQUIRE(graph.airlineExists(kug, baie) == true);
    REQUIRE(graph.airlineExists(kug, wrong) == false);
}

TEST_CASE("airport getairport", "[graph]") {
     AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    
    Airline  b = Airline(kug, baie, 1, "2B");
    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirline(kug, baie, 1, "2B");
    vector<Airport> airports = graph.getAirports();
    for (auto it : airports) {
        cout << it.name << endl;
    }
    REQUIRE(airports.size() == 2);
    
}

TEST_CASE("aiportgraph test insertairport function", "[graph]") {
    // AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
   
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
   
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirport(cfb);
    graph.insertAirport(baker);
    Airport wrong = Airport("Chinese ckae Airport", " 7", 23.9083, 84.2344);
    
    
    
    REQUIRE(graph.airportExists(kug) == true);
    REQUIRE(graph.airportExists(baie) == true);
    REQUIRE(graph.airportExists(cfb) == true);
    REQUIRE(graph.airportExists(baker) == true);
    REQUIRE(graph.airportExists(wrong) == false);

}

TEST_CASE("airportgraph test airline exists", "[graph]") {
    //AirportGraph here = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
   
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirport(cfb);
    graph.insertAirport(baker);
    Airline j = Airline(kug, cfb, 0, "2J");
    Airline  b = Airline(kug, baker, 1, "2B");
    Airline h = Airline(baker, baie, 2, "3H");
    Airline bb = Airline(cfb, baker, 3, "2B");
    graph.insertAirline(kug, baie, 1, "2B");
    graph.insertAirline(kug, cfb, 0, "2J");
   
    graph.insertAirline(baker, baie, 2, "3H");
     
    graph.insertAirline(cfb, baker, 3, "2B");
   
     Airport wrong = Airport("Chinese ckae Airport", " 7", 23.9083, 84.2344);
    
    REQUIRE(graph.airlineExists(kug, cfb) == true);
    REQUIRE(graph.airlineExists(kug, baie) == true);
    REQUIRE(graph.airlineExists(baker, baie) == true);
    REQUIRE(graph.airlineExists(cfb, baker) == true);
    REQUIRE(graph.airlineExists(wrong, kug) == false);

}

TEST_CASE("airportgraph getadj", "[graph]") {
    AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    vector<Airport> adj = graph.getAdjacent(kug);
    REQUIRE(adj.size() == 2);
}