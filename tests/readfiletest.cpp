#include <catch2/catch_test_macros.hpp>

#include "airport.h"
#include "airline.h"
#include "airportgraph.h"
using namespace std; 

#include <sstream>


TEST_CASE("readfile ", "[readfile]") {
//    string file = file_to_string("../tests/airport.csv");
//    cout << file << endl;
   AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
   
   Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
  
   
   Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
   
   Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
   
   Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
   Airline j = Airline(kug, cfb, 0, "2J");
   Airline  b = Airline(kug, baker, 1, "2B");
   Airline h = Airline(baker, baie, 2, "3H");
   Airline bb = Airline(cfb, baker, 3, "2B");

   map<Airport, map<Airport, Airline>> map = graph.getMap();
   for (auto it : map) {
        Airport here = it.first;
        cout << here.getName() << ": ";
        for (auto i : it.second) {
            Airport th = i.first;
            Airline t = i.second;
            cout << "dest airport: " << th.getName() << " | ";
            cout << "airline id: " << t.getLabel() << " ;;;;  ";
        }
        cout << endl;
   }
   REQUIRE(graph.airportExists(kug) == true);
   REQUIRE(graph.airportExists(baie) == true);
   REQUIRE(graph.airportExists(cfb) == true);
   REQUIRE(graph.airportExists(baker) == true);
   REQUIRE(graph.airlineExists(kug, cfb) == true);
   REQUIRE(graph.airlineExists(kug, baie) == true);
   REQUIRE(graph.airlineExists(baker, baie) == true);
   REQUIRE(graph.airlineExists(cfb, baker) == true);
   
   // for (auto it : map) {
   //    int count = 1;
   //    for (auto i : it.second) {
   //       cout << count << endl;
   //       cout << i.second.getLabel() << endl;
   //       count++;
   //    }
   // }
   // cout << map.size() << endl;
   
   
   
}