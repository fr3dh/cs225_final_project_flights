#pragma once
#include "visualization.h"
#include <iterator>
#include <algorithm>
#include <queue>
//#include <unordered_map>

using namespace std;

class BFS {
  public: 
  /**
      * @brief BFS traversal for graph.
    * @return -return a 2d vector that each vector represent a traversal from the first airport
    */
    BFS(string file1,string file2, AirportGraph graph) {
      //create map for checking whether the airport is visited
      Visualization v = Visualization(file1, file2);
      
      
      PNG image;
      image.readFromFile("../tests/open.png");

      
      animation.addFrame(image);

      //initialize the number of visited airport
      map<Airport, map<Airport, Airline>> airport_graph = graph.getMap();
      for (auto it : airport_graph) {
        if (!visited[it.first]) {
          BFSHelp( it.first,image, graph, v);
        }
      }
      
    }

    void play(string file) {
      animation.write("../images/" + file);
    }
   
   map<Airport, bool> getVisited() {return visited;}
    private:
    Animation animation;
    map<Airport, bool> visited;
     /**
    * @brief BFS traveral helper function.
      * @param visited - map<Airport, bool> for checking whether the airport is visited
      * @param source - the started airport for this traversal
      * @param vec - the reference 2D vectors
    */
    void BFSHelp( Airport source,  PNG& image, AirportGraph graph, Visualization & visualization) {
      
      visited[source] = true;
      
      queue<Airport> q;
      q.push(source);
      
      while (!q.empty()) {
        Airport v = q.front();
        q.pop();
        visualization.AnimateBFS(v, animation, image);
        
        vector<Airport> adj = graph.getAdjacent(v);
        for (unsigned i = 0; i < adj.size(); i++) {
          Airport dest = adj[i];
          if (graph.airlineExists(v, dest) && visited[dest] == false) {
            visited[dest] = true;
            q.push(dest);
            visualization.drawallhelper(visualization.convert(v), visualization.convert(dest), image);
          }
        }
      }
      
    }
};
