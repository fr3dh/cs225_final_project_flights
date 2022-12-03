#include "airport.h"
 void Airport::setName(string n) {name = n;}
     void Airport::setID(string id) {ID = id;}
     void Airport::setLatitude(double lati) {latitude = lati;}
     void Airport::setLongitude(double longi) {longitude = longi;}
     string Airport::getName() {return name;}
     string Airport::getID() { return ID;}
     double Airport::getLatitude() {return latitude;}
     double Airport::getLongitude() {return longitude;}