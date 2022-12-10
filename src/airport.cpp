#include "airport.h"

/*set functions for private variables*/
void Airport::setName(string n) {name = n;}

void Airport::setID(string id) {ID = id;}

void Airport::setLatitude(double lati) {latitude = lati;}

void Airport::setLongitude(double longi) {longitude = longi;}

void Airport::setIATA(string ia) {iata = ia;}

void Airport::setICAO(string ic) {icao = ic;}


/*get functions for private variables*/
string Airport::getName() const {return name;}

string Airport::getID() const { return ID;}

double Airport::getLatitude()const {return latitude;}

double Airport::getLongitude() const {return longitude;}

string Airport::getIATA() const {return iata;}

string Airport::getICAO() const {return icao;}