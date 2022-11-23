#include "graph.h"

Graph::Graph() { /* nothing */ }

vector<Vertex> Graph::getAdjacent(Vertex airport) const {

  // if airport does not exist
  if (!vertexExists(airport)) return vector<Vertex>();

  // get all adjcennt airports
  vector<Vertex> adjacent_airports;

  for (auto iter : airport_graph[airport]) {
    adjacent_airports.push_back(iter.first);
  }
  
  return adjacent_airports;
}

vector<Vertex> Graph::getVertices() const {
  
  // get all airports
  vector<Vertex> airports;
  
  for (auto iter : airport_graph) {
    airports.push_back(iter.first);
  }

  return airports;
}

Edge Graph::getEdge(Vertex source, Vertex destination) const {

  // check whether edge exists
  if (!edgeExists(source, destination)) return Edge();

  return airport_graph[source][destination];
}

bool Graph::vertexExists (Vertex airport) const {
  
  if (airport_graph.find(airport) == airport_graph.end()) return false;

  return true;
}

bool Graph::edgeExists(Vertex source, Vertex destination) const {

  if (!vertexExists(source)) return false;
  if (airport_graph[source].find(destination) == airport_graph[source].end()) return false;

  return true;
}

void Graph::insertVertex(Vertex airport) {

  airport_graph[airport] = map<Vertex, Edge>();
}

bool Graph::removeVertex(Vertex airport) {

  // if airport does not exist
  if (!vertexExists(airport)) return false;
  
  // remove airport
  for (auto iter : airport_graph[airport]) {
    airport_graph[iter.first].erase(airport);
  }

  return true;
}

bool Graph::insertEdge(Vertex source, Vertex destination, double weight, string label) {
  
  // if edge already exists
  if (edgeExists(source, destination)) return false;

  // if source does not exists
  if (!vertexExists(source)) airport_graph[source] = map<Vertex, Edge>();

  airport_graph[source][destination] = Edge(source, destination, weight, label);
}

bool Graph::removeEdge(Vertex source, Vertex destination) {

  // if edge does not exists
  if (!edgeExists(source, destination)) return false;

  airport_graph[source].erase(destination);
}