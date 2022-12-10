#include "airportgraph.h"
#include <iterator>
#include <algorithm>
#include <queue>
//#include <unordered_map>
using namespace std;

int AirportGraph::BFS() {
  map<Airport, bool> visited;
  
  // visited.resize(airport_graph.size());
  int num = 0;
  for (auto it : airport_graph) {
    //int idx = std::distance(airport_graph.begin(), airport_graph.find(it.first));
    if (!visited[it.first]) {

      num += BFS(&visited, it.first);
      
    }
  }
  return num;
}

int AirportGraph::BFS(map<Airport, bool> *visited, Airport source) {
  int num = 1;
  (*visited)[source] = true;
  queue<Airport> q;
  q.push(source);
  
  while (!q.empty()) {
    Airport v = q.front();
    q.pop();
    vector<Airport> adj = getAdjacent(v);
    for (unsigned i = 0; i < adj.size(); i++) {
    
      Airport dest = adj[i];
      
      //int idx = std::distance(airport_graph.begin(), airport_graph.find(dest));
      if (airlineExists(v, dest) && (*visited)[dest] == false) {
        
        (*visited)[dest] = true;
        q.push(dest);
        num++;
      }
    }
  }
  
  return num;
}