#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <set>
#include "airportgraph.h"

using std::string;
using std::pair;
using std::set;
using std::numeric_limits;

class Dijkstra {

  public:

    /**
     * @brief Constructor for building Dijkstra's algorithm.
     * @param graph - the airport graph
     * @param start - the airport to find shortest paths for.
     */
    Dijkstra(AirportGraph graph, Airport start);

    /**
     * @brief Find the shortest path from the starting airport to a specific airport.
     * @param end - the destination airport
     */
    vector<Airport> shortestPath(Airport end);

    /**
     * @brief
     * @param 
     */
    int betweennessCentrality(Airport airport);

  private:

    AirportGraph graph_;
    map<Airport, Airport> prevs_;
    map<Airport, double> distances_;
    Airport start_;

};