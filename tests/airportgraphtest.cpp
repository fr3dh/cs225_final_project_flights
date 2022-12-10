#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;
#include "airportgraph.h"
#include "airport.h"


TEST_CASE("aiportgraph test insertairport function", "[graph]") {
    // AirportGraph graph = AirportGraph("../tests/airport.csv", "../tests/airline.csv");
    AirportGraph graph = AirportGraph();
    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    kug.setIATA("YBB");
    kug.setICAO("CYBB");
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    baie.setIATA("YBC");
    baie.setICAO("CYBC");
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    cfb.setIATA("YBG");
    cfb.setICAO("CYBG");
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);
    graph.insertAirport(kug);
    graph.insertAirport(baie);
    graph.insertAirport(cfb);
    graph.insertAirport(baker);
    Airport wrong = Airport("Chinese ckae Airport", " 7", 23.9083, 84.2344);
    //map<Airport, map<Airport, Airline>> map = graph.getMap();
    
    
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
    kug.setIATA("YBB");
    kug.setICAO("CYBB");
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    baie.setIATA("YBC");
    baie.setICAO("CYBC");
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    cfb.setIATA("YBG");
    cfb.setICAO("CYBG");
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
    //graph.clean();
     Airport wrong = Airport("Chinese ckae Airport", " 7", 23.9083, 84.2344);
     map<Airport, map<Airport,Airline>> map = graph.getMap();
     for (auto it : map) {
        Airport here = it.first;
        cout << here.getName() << "  ";
        for (auto i : it.second) {
            Airport he = i.first;
            Airline h = i.second;
            cout << he.getName() << " ";
            cout << h.getLabel() << endl;
        }
        cout << endl;
     }
    REQUIRE(graph.airlineExists(kug, cfb) == true);
    REQUIRE(graph.airlineExists(kug, baie) == true);
    REQUIRE(graph.airlineExists(baker, baie) == true);
    REQUIRE(graph.airlineExists(cfb, baker) == true);
    REQUIRE(graph.airlineExists(wrong, kug) == false);

}
// TEST_CASE("airport_graph Test 1: Verify that getAdjacent works") {
//     Airport A1 = Airport("UK", "1342", 135.02, 142.33);
//     Airport A2 = Airport("US", "1402", 102.34, 167.23);

//     vector<Airport> expect;

//     expect.push_back(A1);
//     expect.push_back(A2);

//     vector<Airport> result;
//     result =getAdjacent(A1);
//     result=(getAdjacent(A2));

//     REQUIRE(result == expect);


// }

// TEST_CASE("airport_graph Test 2: Verify that getAirports works") {
//     Airport A1 = Airport("Shenzhen", "122", 167.2, 23.2);
//     Airport A2 = Airport("Guangzhou", "134", 178.3, 26.2);
//     Airline air = Airline()
//     map<Airport, map<Airport, Airline>> result = {};

// }

// TEST_CASE("airport_graph Test 3: Verify that getAirportFromId works 1") {
//     Airport result = getAirportFromId("1");
//     Airport expected("Goroka Airport", "1", "-6.081689834590001", "145.391998291");
//     REQUIRE(result == expected);
// }

// TEST_CASE("airport_graph Test 4: Verify that getAirportFromId works 2") {
//     Airport result = getAirportFromId("716");
//     Airport expected("Hudiksvall Airport", "716", "61.7681007385", "17.0806999207");
//     REQUIRE(result == expected);
// }