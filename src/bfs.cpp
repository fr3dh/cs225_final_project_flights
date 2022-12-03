#include "airportgraph.h"
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;

void AirportGraph::BFS(Airport source) {
  vector<bool> visited;
  visited.resize(airport_graph.size());
  int source_idx = std::distance(airport_graph.begin(), airport_graph.find(source));
  visited[source_idx] = true;
  queue<Airport> q;
  q.push(source);
  while (!q.empty()) {
    Airport v = q.front();
    q.pop();
    vector<Airport> adj = getAdjacent(v);
    for (unsigned i = 0; i < adj.size(); i++) {
      Airport dest = adj[i];
      int idx = std::distance(airport_graph.begin(), airport_graph.find(dest));
      if (airlineExists(v, dest) && !visited[idx]) {
        visited[idx] = true;
        q.push(dest);
      }
    }
  }

}