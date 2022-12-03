#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;
#include "airportgraph.h"
#include "airport.h"


TEST_CASE("airport_graph Test 1: Verify that getAdjacent works") {
    Airport A1 = Airport("UK", "1342", 135.02, 142.33);
    Airport A2 = Airport("US", "1402", 102.34, 167.23);

    vector<Airport> expect;

    expect.push_back(A1);
    expect.push_back(A2);

    vector<Airport> result;
    result =getAdjacent(A1);
    result=(getAdjacent(A2));

    REQUIRE(result == expect);


}

TEST_CASE("airport_graph Test 2: Verify that getAirports works") {
    Airport A1 = Airport("Shenzhen", "122", 167.2, 23.2);
    Airport A2 = Airport("Guangzhou", "134", 178.3, 26.2);
    Airline air = Airline()
    map<Airport, map<Airport, Airline>> result = {};

}

TEST_CASE("airport_graph Test 3: Verify that getAirportFromId works 1") {
    Airport result = getAirportFromId("1");
    Airport expected("Goroka Airport", "1", "-6.081689834590001", "145.391998291");
    REQUIRE(result == expected);
}

TEST_CASE("airport_graph Test 4: Verify that getAirportFromId works 2") {
    Airport result = getAirportFromId("716");
    Airport expected("Hudiksvall Airport", "716", "61.7681007385", "17.0806999207");
    REQUIRE(result == expected);
}