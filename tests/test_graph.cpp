#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include<algorithm>
using namespace std;
#include "airportgraph.h"
#include "airport.h"


TEST_CASE("airportExists", "[graph]") {
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    Airport wrong = Airport("B", "4", 34.342, 34.341);
    graph.insertAirport(kug);
    REQUIRE(graph.airportExists(kug) == true);
    REQUIRE(graph.airportExists(wrong) == false);
}


TEST_CASE("airlineExists", "[graph]") {
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);

    Airline  b = Airline(kug, baie, 1, "2B");

    Airport wrong = Airport("B", "4", 34.342, 34.341);

    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirline(kug, baie, 1, "2B");
    
    
    REQUIRE(graph.airlineExists(kug, baie) == true);
    REQUIRE(graph.airlineExists(baie, kug) == false);
    REQUIRE(graph.airlineExists(kug, wrong) == false);
}


TEST_CASE("getAirports", "[graph]") {
    AirportGraph graph = AirportGraph();

    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    
    Airline  b = Airline(kug, baie, 1, "2B");
    Airport wrong = Airport("B", "4", 34.342, 34.341);

    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirline(kug, baie, 1, "2B");

    vector<Airport> airports = graph.getAirports();
    
    REQUIRE(airports.size() == 2);
    REQUIRE(find(airports.begin(), airports.end(), kug) != airports.end());
    REQUIRE(find(airports.begin(), airports.end(),baie) != airports.end());
    REQUIRE(find(airports.begin(), airports.end(),wrong) == airports.end());
    
}

TEST_CASE("getAdjacent", "[graph]") {
    AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");

    
   Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
   Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
   Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
   Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);

   Airline j = Airline(kug, cfb, 0, "2J");
   Airline  b = Airline(kug, baker, 1, "2B");
   Airline h = Airline(baker, baie, 2, "3H");
   Airline bb = Airline(cfb, baker, 3, "2B");

    vector<Airport> adj = graph.getAdjacent(kug);

    REQUIRE(adj.size() == 2);
    REQUIRE(find(adj.begin(), adj.end(), baie) != adj.end());
    REQUIRE(find(adj.begin(), adj.end(), cfb) != adj.end());
    REQUIRE(find(adj.begin(), adj.end(), baker) == adj.end());

}

TEST_CASE("insertAirport", "[graph]") {
    
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

TEST_CASE("insertAirline", "[graph]") {
    //AirportGraph here = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    AirportGraph graph = AirportGraph();

    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
 
    Airline j = Airline(kug, cfb, 0, "2J");
    Airline  b = Airline(kug, baker, 1, "2B");
    Airline h = Airline(baker, baie, 2, "3H");
    Airline bb = Airline(cfb, baker, 3, "2B");

    graph.insertAirline(kug, baie, 1, "2B");
    graph.insertAirline(kug, cfb, 0, "2J");
   
    graph.insertAirline(baker, baie, 2, "3H");
     
    graph.insertAirline(cfb, baker, 3, "2B");
   
     Airport wrong = Airport("Chinese cake Airport", " 7", 23.9083, 84.2344);
    
    REQUIRE(graph.airlineExists(kug, cfb) == true);
    REQUIRE(graph.airlineExists(kug, baie) == true);
    REQUIRE(graph.airlineExists(baker, baie) == true);
    REQUIRE(graph.airlineExists(cfb, baker) == true);
    REQUIRE(graph.airlineExists(wrong, kug) == false);

}
