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
   // cout << it ->first << "  " << it->second[0] << endl;
    Airport ap(it -> first, it -> second[0], stringToDouble(it -> second[1]), stringToDouble(it -> second[2]));
    ap.setIATA(it->second[3]);
    ap.setICAO(it ->second[4]);
    airports.push_back(ap);
    insertAirport(ap);
  }
}

void AirportGraph::insertAllAirlines(string const & AirlineFileName) {
  vector<vector<string>> airlineList;
  map<pair<vector<Airport>, double>, string> airlineMap;  
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
  
  //convert 2d vector to a map (containing useful information)
  for (size_t row = 0; row < airlineList.size(); row++) {
    vector<Airport> info;
    //label
    string label = airlineList[row][0];
    //source id
    info.push_back(getAirportFromId(airlineList[row][3], airlineList[row][2]));
    //destination id
    info.push_back(getAirportFromId(airlineList[row][5], airlineList[row][4]));
    //weight
    // info.push_back((string)calculateWeight(list[row][3], list[row][5]));
    

    airlineMap.insert(pair<pair<vector<Airport>, double>, string>( make_pair(info, calculateWeight(stringToInt(airlineList[row][3]), airlineList[row][2],  stringToInt(airlineList[row][5]),  airlineList[row][4])), label));
  }

  //insert airlines to the graph from the map
  for (map<pair<vector<Airport>, double>, string>::iterator it = airlineMap.begin(); it != airlineMap.end(); it++) {
    // Airline al(it -> second.first[0], it -> second.first[1], it -> second.second, it -> first);
    // vector<Airport> air = it->first.first;
    // cout << "source: " <<air[0].getName() << "  |  ";
    // cout << "dest: " << air[1].getName() << "  |  ";
    // cout << "airline: " << it->second << endl;
    // Airline airline = Airline(it -> first.first[0], it -> first.first[1], it -> first.second, it -> second);
    //airlines.insert(pair<pair<Airport, Airport>, Airline>(make_pair(it -> first.first[0], it -> first.first[1]), airline));
    //cout << it -> first.first[0].getName() << "  \"  " << it -> first.first[1].getName() << "   " << it -> first.second << " " << it -> second << endl;
    insertAirline(it -> first.first[0], it -> first.first[1], it -> first.second, it -> second);
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


double AirportGraph::calculateWeight(int sourceId, string sourcecode, int destinationId, string destinationcode) {
  Airport src = getAirportFromId(to_string(sourceId), sourcecode);
  Airport dest = getAirportFromId(to_string(destinationId), destinationcode);
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

Airport AirportGraph::getAirportFromId(string id, string code) {
  // vector<Airport> airports = getAirports();
  for (unsigned i = 0; i < airports.size(); i++) {
    // find the corresponding airport of the id from the aiports vector
    Airport ap = airports[i];
    if (ap.getID()[0] != '\"' && id[0] != '\"') {
        if (ap.getID() == id) return ap;
    } else if (code[0] != '\"') {
      if (code.size() == 3) {
        if (ap.getIATA() == code) return ap;
      }
      else if (code.size() == 4) {
        if (ap.getICAO() == code) return ap;
      }
    }

  }
  // if id does not exist
  return Airport();
}