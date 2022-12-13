#include "dijkstra.h"
#include "../lib/heap/heap.cpp"
#include <iostream>

Dijkstra::Dijkstra(AirportGraph graph, Airport start) {

  // initializations
  graph_ = graph;
  start_ = start;
  set<Airport> visited_;
  vector<Airport> airports = graph.getAirports();
  for (auto airport : airports) {
    distances_.insert(pair<Airport, double>(airport, numeric_limits<double>::infinity()));
    prevs_.insert(pair<Airport, Airport>(airport, airport));
  }
  distances_[start] = 0.0;

  heap<pair<Airport, double>> airport_heap;
  for (auto pair : distances_) {
    airport_heap.push(pair);
  }

  for (size_t i = 0; i < distances_.size(); i++) {
    Airport u = airport_heap.pop().first;
    visited_.insert(u);

    for (auto ip : graph_.getAdjacent(u)) {
      if (visited_.find(ip) == visited_.end()) {
        if (graph_.getAirline(u, ip).weight + distances_[u] < distances_[ip]) {
          std::pair<Airport, double> to_update = *distances_.find(ip);
          distances_[ip] = graph_.getAirline(u, ip).weight + distances_[u];
          std::pair<Airport, double> update = *distances_.find(ip);
          airport_heap.updateElem(to_update, update);
          prevs_[ip] = u; 
        }
      }
    }
  }
}

vector<Airport> Dijkstra::shortestPath(Airport end) {

  Airport curr = end;
  vector<Airport> inversed_path;

  while (!(curr == start_)) {
    inversed_path.push_back(curr);
    curr = prevs_[curr];
  }
  inversed_path.push_back(start_);

  vector<Airport> path;
  for (size_t i = inversed_path.size()-1; i > 0; i--) {
    path.push_back(inversed_path[i]);
  }
  path.push_back(inversed_path[0]);

  return path;
}

int Dijkstra::betweennessCentrality(Airport airport) {
  int count = 0;
  for (auto pair : prevs_) {
    if (pair.second == airport) {
      count++;
    }
  }

  return count;
}