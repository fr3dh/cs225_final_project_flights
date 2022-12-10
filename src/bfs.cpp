#include "airportgraph.h"
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;

int AirportGraph::BFS() {
  vector<bool> visited;
  visited.resize(airport_graph.size());
  int num = 0;
  for (auto it : airport_graph) {
    int idx = std::distance(airport_graph.begin(), airport_graph.find(it.first));
    if (!visited[idx]) {
      BFS(&visited, it.first);
      num++;
    }
  }
  return num;
}

void AirportGraph::BFS(vector<bool> *visited, Airport source) {
  
  
  int source_idx = std::distance(airport_graph.begin(), airport_graph.find(source));
  (*visited)[source_idx] = true;
  queue<Airport> q;
  q.push(source);
  while (!q.empty()) {
    Airport v = q.front();
    q.pop();
    vector<Airport> adj = getAdjacent(v);
    for (unsigned i = 0; i < adj.size(); i++) {
      Airport dest = adj[i];
      int idx = std::distance(airport_graph.begin(), airport_graph.find(dest));
      if (airlineExists(v, dest) && visited->at(idx) == false) {
        (*visited)[idx] = true;
        q.push(dest);
      }
    }
  }

}