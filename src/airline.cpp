#include "airline.h"

 void Airline::setSource(Airport sour) {source = sour;}
 void Airline::setDestination(Airport dest) {destination = dest;}
void Airline::setWeight(double wei) {weight = wei;}
    void Airline::setLabel(string lab) {label = lab;} 
    Airport Airline::getSource() {return source;}
    Airport Airline::getDestination() {return destination;}
    double Airline::getWeight() {return weight;}
    string Airline::getLabel() {return label;}