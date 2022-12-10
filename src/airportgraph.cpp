#include "airportgraph.h"
#include <set>
using namespace std;

AirportGraph::AirportGraph() { /* nothing */ }


bool AirportGraph::airportExists (Airport airport) const {
  
  // if (airport_graph.find(airport) == airport_graph.end()) return false;

  // return true;
  // if (airport_graph.count(airport) == 0) return false;
  // return true;
  // if (airport_graph.size() == 0) return false;
  bool check = false;
  for (auto it : airport_graph) {
    Airport airp = it.first;
   
    if (airp == airport) check = true;
  }
  
  return check;
  //   if (airport  == airp) return true;
  // }
  // return false;
  
  //cout <<airport.getName() << " "<< airport_graph.count(airport) << endl;
  //return airport_graph.count(airport) != 0;
}

bool AirportGraph::airlineExists(Airport source, Airport destination) const {

  if (!airportExists(source)) return false;
  bool check = false;
  for (auto it : airport_graph) {
    Airport sour = it.first;
    if (sour == source) {
      for (auto i : it.second) {
        Airport dest = i.first;
        if (dest == destination) check = true;
      }
    }
  }
  // if (airport_graph[source].find(destination) == airport_graph[source].end()) return false;

  return check;

}

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


void AirportGraph::insertAirport(Airport airport) {
  if (!airportExists(airport)) airport_graph[airport] = map<Airport, Airline>();
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
  
  //if source does not exists
  // if (!airportExists(source))  {
  //   cout << " here " << endl;
  //   airport_graph[source] = map<Airport, Airline>();
  
  //insertAirport(source);
  if (!airportExists(source)) insertAirport(source);
  Airline airline = Airline(source, destination, weight, label);
  
  airport_graph[source].insert(pair<Airport, Airline>(destination, airline));
  airport_graph[source][destination] =airline;

  // //airport_graph[source][destination] = airline;
  // // cout << " =-------------=" << endl;
  //  //cout << source.getName() << " " << destination.getName() << " "  << airport_graph[source][destination].getLabel() << endl;
  // // cout << " =-------------=" << endl;
  
  // for (auto it : airport_graph) {
  //   Airport sour = it.first;
  //   if (sour == source) {
  //     if (it.second.find(destination) == it.second.end()) airport_graph[source].insert(pair<Airport, Airline>(destination, airline));
  //   }
  // }
  
  return true;
}

bool AirportGraph::removeAirline(Airport source, Airport destination) {

  // if airline does not exists
  if (!airlineExists(source, destination)) return false;

  airport_graph[source].erase(destination);
  return true;
}

// void AirportGraph::clean() {
//   //set<Airport> sour;
//   set<Airport> dest;
//   map<Airport, map<Airport, Airline>>::iterator it;
//   for (it = airport_graph.begin(); it != airport_graph.end(); it++) {
//       Airport source = it->first;
      
//     for (auto i : it->second) {
//       Airport destination = i.first;
//       Airline airline = i.second;
//       if (dest.find(destination) != dest.end()) {
        
//         airport_graph.erase(it);
//         break;
//       }
//       cout << "here" << endl;
//       dest.insert(destination);

//     }
  
//   }
// }