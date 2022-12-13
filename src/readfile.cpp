#include "airportgraph.h"
#include <cstdlib>
using namespace std;


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
      str = Trim(str);
      str = TrimChar(str, '"');
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
    
    //iata
    info.push_back(airportList[row][4]);

    //icao
    info.push_back(airportList[row][5]);
    
    
    airportMap.insert(pair<string, vector<string>>(airportList[row][1], info));
  }

  
  //insert airports to the graph from the map
  for (map<string, vector<string>>::iterator it = airportMap.begin(); it != airportMap.end(); it++) {
   
    Airport ap(it -> first, it -> second[0], stringToDouble(it -> second[1]), stringToDouble(it -> second[2]));
    insertAirport(ap);
  }
}

void AirportGraph::insertAllAirlines(string const & AirlineFileName) {
  vector<vector<string>> airlineList;
  
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
      str = Trim(str);
      line.push_back(str);
    }
    airlineList.push_back(line);
  }
  //store source, destination and weights for the airline
  // vector<Airport> source;
  // vector<Airport> destination;
  // vector<string> airline;
  // vector<double> weights;

  map<pair<Airport, Airport>, pair<string, double>> map;
  //extract usefule information from the 2d vector into vectors
  for (size_t row = 0; row < airlineList.size(); row++) {
    
    //label
    string label = airlineList[row][0];
    // airline.push_back(label);

    //source airport
    Airport sour = getAirportFromId(airlineList[row][3]);
    //source.push_back(sour);

    //destination airport
    Airport dest = getAirportFromId(airlineList[row][5]);
    //destination.push_back(dest);
    //weight
    double weight = calculateWeight(stringToInt(airlineList[row][3]),  stringToInt(airlineList[row][5]));
    //weights.push_back(weight);
    pair<Airport, Airport> key = make_pair(sour, dest);
    pair<string, double> value = make_pair(label, weight);
    map[key] = value;

  }
  

  //insert airlines to the graph from vectors
  // for (unsigned i = 0; i < source.size(); i++) {
  //   insertAirline(source[i], destination[i], weights[i],airline[i]);
  // }
  for (auto it : map) {
    insertAirline(it.first.first, it.first.second, it.second.second, it.second.first);
  }
  
}



double AirportGraph::stringToDouble(const std::string & s) {
    double val;
    std::stringstream ss;
    ss << s;
    ss >> val;
    return val;
}

int AirportGraph::stringToInt(const std::string & s) {
    int val;
    std::stringstream ss;
    ss << s;
    ss >> val;
    return val;
}


double AirportGraph::calculateWeight(int sourceId,int destinationId) {
  Airport src = getAirportFromId(to_string(sourceId));
  Airport dest = getAirportFromId(to_string(destinationId));
  double srclong = src.longitude;
  double srclati = src.latitude;
  double destlong = src.longitude;
  double destlati = src.latitude;

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
    if (airports[i].ID == id) {
      return airports[i];
    }
  }
  // if id does not exist
  return Airport();
}