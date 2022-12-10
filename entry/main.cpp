#include <iostream>
#include "airport_graph.h"

int main() {
  AirportGraph graph = AirportGraph();

  Airport airport = Airport("LA", "123", 24.5, 24.5);

  graph.insertAirport(airport);
  if (graph.airportExists(airport)) {
    std::cout << "Hello World!" << std::endl;
  }
}