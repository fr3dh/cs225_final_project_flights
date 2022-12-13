#include <catch2/catch_test_macros.hpp>

#include "airport.h"
#include "airline.h"
#include "airportgraph.h"
using namespace std; 

#include <sstream>


TEST_CASE("readfile-smale", "[readfile]") {

   AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
   
   Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
   Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
   Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
   Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);

   Airline j = Airline(kug, cfb, 0, "2J");
   Airline  b = Airline(kug, baker, 1, "2B");
   Airline h = Airline(baker, baie, 2, "3H");
   Airline bb = Airline(cfb, baker, 3, "2B");

   REQUIRE(graph.airportExists(kug) == true);
   REQUIRE(graph.airportExists(baie) == true);
   REQUIRE(graph.airportExists(cfb) == true);
   REQUIRE(graph.airportExists(baker) == true);

   REQUIRE(graph.airlineExists(kug, cfb) == true);
   REQUIRE(graph.airlineExists(kug, baie) == true);
   REQUIRE(graph.airlineExists(baker, baie) == true);
   REQUIRE(graph.airlineExists(cfb, baker) == true);
}

TEST_CASE("readfile-large", "[readfile]") {
   AirportGraph graph = AirportGraph("../tests/airport1.csv", "../tests/airline1.csv");
   Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
   Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
   Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
   Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
   Airport cyaw = Airport("Halifax / CFB Shearwater Heliport", "5", 44.6397, -63.4994);
   Airport yay = Airport("St. Anthony Airport", "6", 51.3919, -56.0831);
   Airport yaz = Airport("Tofino / Long Beach Airport", "7", 49.0798, -125.7756);


   Airline j = Airline(kug, cfb, 0, "2J");
   Airline  b = Airline(kug, baker, 1, "2B");
   Airline h = Airline(baker, baie, 2, "3H");
   Airline bb = Airline(cfb, baker, 3, "2B");
   Airline k = Airline(cyaw, yay, 0, "4K");
   Airline g = Airline(yay, yaz, 0, "5G");
   Airline hh = Airline(baie, cfb, 1, "4H");

   REQUIRE(graph.airportExists(kug) == true);
   REQUIRE(graph.airportExists(baie) == true);
   REQUIRE(graph.airportExists(cfb) == true);
   REQUIRE(graph.airportExists(baker) == true);
   REQUIRE(graph.airportExists(cyaw) == true);
   REQUIRE(graph.airportExists(yay) == true);
   REQUIRE(graph.airportExists(yaz) == true);

   REQUIRE(graph.airlineExists(kug, cfb) == true);
   REQUIRE(graph.airlineExists(kug, baie) == true);
   REQUIRE(graph.airlineExists(baker, baie) == true);
   REQUIRE(graph.airlineExists(cfb, baker) == true);
   REQUIRE(graph.airlineExists(cyaw, yay) == true);
   REQUIRE(graph.airlineExists(yay, yaz) == true);
   REQUIRE(graph.airlineExists(baie, cfb) == true);
}

TEST_CASE("readfile 1000", "[readfile]") {
   AirportGraph graph = AirportGraph("../tests/airports1000.csv", "../tests/routes1000.csv");

   map<Airport, map<Airport, Airline>> map = graph.getMap();

   REQUIRE((int)map.size() == 947);

}

TEST_CASE("readfile 4000", "[readfile]") {
   AirportGraph graph = AirportGraph("../tests/airport4000.csv", "../tests/routes4000.csv");

   map<Airport, map<Airport, Airline>> map = graph.getMap();

   REQUIRE((int)map.size() == 2710);

}

