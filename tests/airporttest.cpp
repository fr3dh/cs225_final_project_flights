#include <catch2/catch_test_macros.hpp>

#include "airport.h"
#include <iostream>
using namespace std;

TEST_CASE("aiport operator","[airport]") {
    Airport a("Kugaaruk Airport","Pelly Bay", 68.534401,-89.808098);
    Airport b("Kugaaruk Airport","Pelly Bay",49.13249969482422,-68.20439910888672);
    bool check = a==b;
    //cout << "here" << endl;
    REQUIRE(check == true);
}
TEST_CASE("airport empty constructor", "[airport]") {
    Airport a = Airport();
    REQUIRE(a.getName() == "");
    REQUIRE(a.getID() == "");
    REQUIRE(a.getLatitude() == -1);
    REQUIRE(a.getLongitude() == -1);
}

TEST_CASE("airport  constructor", "[airport]") {
    Airport a("Kugaaruk Airport","Pelly Bay", 68.534401,-89.808098); 
    REQUIRE(a.getName() == "Kugaaruk Airport");
    REQUIRE(a.getID() == "Pelly Bay");
    REQUIRE(a.getLatitude() == 68.534401);
    REQUIRE(a.getLongitude() == -89.808098);
}