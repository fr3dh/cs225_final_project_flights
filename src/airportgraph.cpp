#include "airportgraph.h"

using namespace std;

AirportGraph::AirportGraph() { /* nothing */ }

AirportGraph::AirportGraph(string const & AirportFileName, string const & AirlineFileName) {
  insertAllAirports(AirportFileName);
  insertAllAirlines(AirlineFileName);
}

void AirportGraph::insertAllAirports(string const & AirportFileName) {
  vector<vector<string>> airportList;
  map<string, vector<string>> airportMap;  
  //read file to a 2d vector (containing all information)
  ifstream file(AirportFileName);
  while(file) {
    string s;
    if (!getline(file,s)) {
      break;
    }
    istringstream ss(s);
    vector<string> line;
    while(ss) {
      string str;
      if (!getline(ss, str, ',')) {
        break;
      }
      // string::iterator end_pos = remove(str.begin(), str.end(), ' ');
      // str.erase(end_pos, str.end());
      remove(str.begin(), str.end(), ' ');
      line.push_back(str);
    }
    airportList.push_back(line);
  }
  //convert 2d vector to a map (containing useful information)
  for (size_t row = 0; row < airportList.size(); row++) {
    vector<string> info;
    //id
    info.push_back(airportList[row][0]);
    //latitude
    info.push_back(airportList[row][6]);
    //longitude
    info.push_back(airportList[row][7]);
    airportMap.insert(pair<string, vector<string>>(airportList[row][1], info));
  }
  //insert airports to the graph from the map
  for (map<string, vector<string>>::iterator it = airportMap.begin(); it != airportMap.end(); it++) {
    Airport ap(it -> first, it -> second[0], stod(it -> second[1]), stod(it -> second[2]));
    insertAirport(ap);
  }
}

void AirportGraph::insertAllAirlines(string const & AirlineFileName) {
  vector<vector<string>> airlineList;
  map<string, pair<vector<Airport>, double>> airlineMap;  
  //read file to a 2d vector (containing all information)
  ifstream file(AirlineFileName);
  while(file) {
    string s;
    if (!getline(file,s)) {
      break;
    }
    istringstream ss(s);
    vector<string> line;
    while(ss) {
      string str;
      if (!getline(ss, str, ',')) {
        break;
      }
      // string::iterator end_pos = remove(str.begin(), str.end(), ' ');
      // str.erase(end_pos, str.end());
      remove(str.begin(), str.end(), ' ');
      line.push_back(str);
    }
    airlineList.push_back(line);
  }
  //convert 2d vector to a map (containing useful information)
  for (size_t row = 0; row < airlineList.size(); row++) {
    vector<Airport> info;
    //label
    string label = airlineList[row][0] + airlineList[row][1];
    //source
    info.push_back(getAirportFromId(airlineList[row][3]));
    //destination
    info.push_back(getAirportFromId(airlineList[row][5]));
    //weight
    // info.push_back((string)calculateWeight(list[row][3], list[row][5]));
    airlineMap.insert(pair<string, pair<vector<Airport>, double>>(label, make_pair(info, calculateWeight(stoi(airlineList[row][3]), stoi(airlineList[row][5])))));
  }
  //insert airlines to the graph from the map
  for (map<string, pair<vector<Airport>, double>>::iterator it = airlineMap.begin(); it != airlineMap.end(); it++) {
    // Airline al(it -> second.first[0], it -> second.first[1], it -> second.second, it -> first);
    insertAirline(it -> second.first[0], it -> second.first[1], it -> second.second, it -> first);
  }
}

double AirportGraph::calculateWeight(int sourceId, int destinationId) {
  Airport src = getAirportFromId(to_string(sourceId));
  Airport dest = getAirportFromId(to_string(destinationId));
  double srclong = src.getLongitude();
  double srclati = src.getLatitude();
  double destlong = src.getLongitude();
  double destlati = src.getLatitude();

  double dislong = destlong - srclong;
  double dislat = destlati - srclati;

  double result = pow(sin(dislat / 2), 2) + cos(srclati) * cos(destlati) * pow(sin(dislong / 2), 2);
  result = 2 * asin(sqrt(result));
  result *= 6371;

  return result;
}

Airport AirportGraph::getAirportFromId(string id) {
  vector<Airport> airports = getAirports();
  for (unsigned i = 0; i < airports.size(); i++) {
    // find the corresponding airport of the id from the aiports vector
    if (airports[i].getID() == id) {
      return airports[i];
    }
  }
  // if id does not exist
  return Airport();
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
  return true;
}

bool AirportGraph::removeAirline(Airport source, Airport destination) {

  // if airline does not exists
  if (!airlineExists(source, destination)) return false;

  airport_graph[source].erase(destination);
  return true;
}