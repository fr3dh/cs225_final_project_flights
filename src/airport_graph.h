#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "airport.h"
#include "airline.h"

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

  private:
    mutable map<Airport, map<Airport, Airline>> airport_graph;

};