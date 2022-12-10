#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include "airport.h"
#include "airline.h"
#include "utils/utils.h"

using std::string;
using std::vector;
using std::map;

class AirportGraph {

  public:
    /**
     * @brief Constructor to create an empty airport graph.
     */
    
    AirportGraph();

    /**
     * @brief Constructor to create an airport graph.
     * @param airportFileName - name of the airport file to generate the graph
     * @param airlineFileName - name of the airline file to generate the graph
     */
    AirportGraph(string const & airportFileName, string const & airlineFileName);

    /**
     * @brief Insert all airports in the graph.
     * @param airportFileName - name of the airport file to generate the graph
     */
    void insertAllAirports(string const & airportFileName);

    /**
     * @brief Insert all airlines in the graph.
     * @param airlineFileName - name of the airline file to generate the graph
     */
    void insertAllAirlines(string const & airlineFileName);

    //Use as reference from GeeksforGeeks.
    double calculateWeight(int sourceId,string sourcecode,  int destinationId, string destinationcode);

    /**
     * @brief Get airport from the given id.
     * @param id - id of the airport we want to find
     * @param code - IATA/ICAO of the airport we want to find
     * @return an airport
     */
    Airport getAirportFromId(string id, string code);

    /**
     * @brief Get all adjacent airports to the parameter airport.
     * @param airport - airport to get neighbors from
     * @return a vector of airports
     */ 
    vector<Airport> getAdjacent(Airport airport) const;
    
    /**
     * @brief Get all airports in the airport graph.
     * @return a vector of all airports in the airport graph
     */
    vector<Airport> getAirports() const;

    /**
     * @brief Get an airline between two airports.
     * @param source - one airport the airline is connected to
     * @param destination - the other airport the airline is connected to
     * @return - if exist, return the corresponding airline
     *         - if airline doesn't exist, return Airline()
     */
    Airline getAirline(Airport source, Airport destination) const;

    /**
     * @brief Check if the given airport exists.
     * @param airport - the airport
     * @return - if airport exists, true
     *         - if airport doesn't exist, return false
     */
    bool airportExists (Airport airport) const;

    /**
     * @brief Check if airline exists between two airport exists.
     * @param source - one airport the airline is connected to
     * @param destination - the other airport the airline is connected to
     * @return - if airline exists, true
     *         - if airline doesn't exist, return false
     */
    bool airlineExists(Airport source, Airport destination) const;

    /**
     * @brief Insert a new airport into the airport graph.
     * @param airport - the airport
     */
    void insertAirport(Airport airport);

    /**
     * @brief Remove a given airport from the airport graph.
     * @param airport - the airport to remove
     * @return - if airport exists, remove airport and return true
     *         - if not, return false
     */
    bool removeAirport(Airport airport);

    /**
     * @brief insert an airline between two airports.
     * @param source - one airport the airline is connected to
     * @param destination - the other airport the airline is connected to
     * @return whether inserting the airline was successful
     */
    bool insertAirline(Airport source, Airport destination, double weight, string label);

    /**
     * @brief the airline between two airpoints.
     * @param source - one airport the airline is connected to
     * @param destination - the other airport the airline is connected to
     * @return - if airline exists, remove it and return true
     *         - if not, return false
     */
    bool removeAirline(Airport source, Airport destination);

    double stringToDouble(const std::string & s);
    int stringToInt(const std::string & s);
    /*BFS Traversal*/
    void BFS(vector<bool> *visited, Airport source);
    int BFS();
     
    //graph clean
    //void clean();

    /*test*/
    map<Airport, map<Airport, Airline>> getMap() {return airport_graph;}

  private:
    mutable map<Airport, map<Airport, Airline>> airport_graph;
    vector<Airport> airports;
    //map<pair<Airport, Airport>, Airline> airlines;
    
};