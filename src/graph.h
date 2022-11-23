#include <string>
#include <vector>
#include <unordered_map>
#include "vertex.h"
#include "edge.h"

using namespace std;

class Graph {

  public:
    /**
     * Constructor to create an empty graph.
     */
    Graph();

  private:
    unordered_map<Vertex, unordered_map<Vertex, Edge>> airport_graph;

};