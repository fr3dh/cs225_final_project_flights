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
   //cout << it ->first << "  " << it->second[0] << endl;
    Airport ap(it -> first, it -> second[0], stringToDouble(it -> second[1]), stringToDouble(it -> second[2]));
    airports.push_back(ap);
    insertAirport(ap);
  }
}

void AirportGraph::insertAllAirlines(string const & AirlineFileName) {
  vector<vector<string>> airlineList;
  //map<pair<vector<Airport>, double>, string> airlineMap;  
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
  vector<Airport> source;
  vector<Airport> destination;
  vector<string> airline;
  vector<double> weights;
  //convert 2d vector to a map (containing useful information)
  for (size_t row = 0; row < airlineList.size(); row++) {
    //vector<Airport> info;
    //label
    string label = airlineList[row][0];
    airline.push_back(label);
    //source id
    Airport sour = getAirportFromId(airlineList[row][3]);
    source.push_back(sour);
    //destination id
    Airport dest = getAirportFromId(airlineList[row][5]);
    destination.push_back(dest);
    //weight
    // info.push_back((string)calculateWeight(list[row][3], list[row][5]))
    double weight = calculateWeight(stringToInt(airlineList[row][3]),  stringToInt(airlineList[row][5]));
    weights.push_back(weight);
    //airlineMap.insert(pair<pair<vector<Airport>, double>, string>( make_pair(info, calculateWeight(stringToInt(airlineList[row][3]),  stringToInt(airlineList[row][5]))), label));
  }
  //cout << airlineMap.size()  << endl;
  //insert airlines to the graph from the map
  for (unsigned i = 0; i < source.size(); i++) {
    // cout << "source: " <<source[i].name << "  |  ";
    // cout << "dest: " << destination[i].name << "  |  ";
    // cout << "airline: " << airline[i] << endl;
    insertAirline(source[i], destination[i], weights[i],airline[i]);
  }
  // for (map<pair<vector<Airport>, double>, string>::iterator it = airlineMap.begin(); it != airlineMap.end(); it++) {
  //   // Airline al(it -> second.first[0], it -> second.first[1], it -> second.second, it -> first);
  //   vector<Airport> air = it->first.first;
  //   cout << "source: " <<air[0].name << "  |  ";
  //   cout << "dest: " << air[1].name << "  |  ";
  //   cout << "airline: " << it->second << endl;
    
  //   insertAirline(it -> first.first[0], it -> first.first[1], it -> first.second, it -> second);
  // }
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
  //vector<Airport> airports = getAirports();
  for (unsigned i = 0; i < airports.size(); i++) {
    // find the corresponding airport of the id from the aiports vector
    if (airports[i].ID == id) {
      return airports[i];
    }
  }
  // if id does not exist
  return Airport();
}