#include <string>
#include <vector>
#include <map>
#include "vertex.h"
#include "edge.h"

using namespace std;

class Graph {

  public:
    /**
     * Constructor to create an empty graph.
     */
    Graph();

    /**
     * Gets all adjacent vertices to the parameter vertex.
     * @param source - vertex to get neighbors from
     * @return a vector of vertices
     */
    vector<Vertex> getAdjacent(Vertex airport) const;
    
    /**
     * Gets all vertices in the graph.
     * @return a vector of all vertices in the graph
     */
    vector<Vertex> getVertices() const;

    /**
     * Gets an edge between two vertices.
     * @param source - one vertex the edge is connected to
     * @param destination - the other vertex the edge is connected to
     * @return - if exist, return the corresponding edge
     *         - if edge doesn't exist, return Edge()
     */
    Edge getEdge(Vertex source, Vertex destination) const;

    /**
     * Checks if the given vertex exists.
     * @return - if Vertex exists, true
     *         - if Vertex doesn't exist, return false
     */
    bool vertexExists (Vertex airport) const;

    /**
     * Checks if edge exists between two vertices exists.
     * @return - if Edge exists, true
     *         - if Edge doesn't exist, return false
     */
    bool edgeExists(Vertex source, Vertex destination) const;

    /**
     * Inserts a new vertex into the graph and initializes its label as "".
     * @param v - the name for the vertex
     */
    void insertVertex(Vertex airport);

    /**
     * @brief a given airport from the airport_graph.
     * @param airport - the vertex to remove
     * @return - if airport exists, remove airport and return true
     *         - if not, return false
     */
    bool removeVertex(Vertex airport);

    /**
     * @brief insert an edge between two vertices.
     * A boolean is returned for use with the random graph generation.
     * Hence, an error is not thrown when it fails to insert an edge.
     * @param source - one vertex the edge is connected to
     * @param destination - the other vertex the edge is connected to
     * @return whether inserting the edge was successful
     */
    bool insertEdge(Vertex source, Vertex destination, double weight, string label);

    /**
     * @brief the edge between two vertices.
     * @param source - one vertex the edge is connected to
     * @param destination - the other vertex the edge is connected to
     * @return - if edge exists, remove it and return removed edge
     *         - if not, return InvalidEdge
     */
    bool removeEdge(Vertex source, Vertex destination);

    /**
     * Sets the weight of the edge between two vertices.
     * @param source - one vertex the edge is connected to
     * @param destination - the other vertex the edge is connected to
     * @param weight - the weight to set to the edge
     * @return - if edge exists, set edge weight and return  edge with new weight
     *         - if not, return InvalidEdge
     */

  private:
    mutable map<Vertex, map<Vertex, Edge>> airport_graph;

};