#include "airport_graph.h"

AirportGraph::AirportGraph() { /* nothing */ }

vector<Airport> AirportGraph::getAdjacent(Airport airport) const {

  // if airport does not exist
  if (!airportExists(airport)) return vector<Airport>();

  // get all adjcennt airports
  vector<Airport> adjacent_airports;

  for (auto iter : airport_graph[airport]) {
    adjacent_airports.push_back(iter.first);
  }
  
  return adjacent_airports;
}

vector<Airport> AirportGraph::getAirports() const {
  
  // get all airports
  vector<Airport> airports;
  
  for (auto iter : airport_graph) {
    airports.push_back(iter.first);
  }

  return airports;
}

Airline AirportGraph::getAirline(Airport source, Airport destination) const {

  // check whether airline exists
  if (!airlineExists(source, destination)) return Airline();

  return airport_graph[source][destination];
}

bool AirportGraph::airportExists (Airport airport) const {
  
  if (airport_graph.find(airport) == airport_graph.end()) return false;

  return true;
}

bool AirportGraph::airlineExists(Airport source, Airport destination) const {

  if (!airportExists(source)) return false;
  if (airport_graph[source].find(destination) == airport_graph[source].end()) return false;

  return true;
}

void AirportGraph::insertAirport(Airport airport) {

  airport_graph[airport] = map<Airport, Airline>();
}

bool AirportGraph::removeAirport(Airport airport) {

  // if airport does not exist
  if (!airportExists(airport)) return false;
  
  // remove airport
  for (auto iter : airport_graph[airport]) {
    airport_graph[iter.first].erase(airport);
  }

  return true;
}

bool AirportGraph::insertAirline(Airport source, Airport destination, double weight, string label) {
  
  // if airline already exists
  if (airlineExists(source, destination)) return false;

  // if source does not exists
  if (!airportExists(source)) airport_graph[source] = map<Airport, Airline>();

  airport_graph[source][destination] = Airline(source, destination, weight, label);
}

bool AirportGraph::removeAirline(Airport source, Airport destination) {

  // if airline does not exists
  if (!airlineExists(source, destination)) return false;

  airport_graph[source].erase(destination);
}