#pragma once
#include "animation/animation.h"

#include "dijkstra.h"
#include "cs225/PNG.h"
#include <vector>
#include <cmath>
// #include <map>
// #include "airport.h"
// #include "airline.h"
// #include "airportgraph.h"
// #include <iterator>
using namespace std;
using namespace cs225;



/**
     * @brief Create Point struct for storing coordinate of airport
     */
struct Point {
  int x;
  int y;

  /**
   * @brief Default constructor, set the point to (0, 0)
   */
  Point() : Point(0, 0) { }

  /**
   * @brief Constructor
   * @param x coordinate of a point
   * @param y coordinate of a point
   */
  Point(int x, int y) : x(x), y(y) { }

  /**
   * overload operator <
   * @param other The other point
   * @return True for smaller, false for otherwise
   */
  bool operator<(const Point &other) const {
    return (x < other.x || y < other.y);
  }

  /**
   * overload operator ==
   * @param other The other point
   * @return True for smaller, false for otherwise
   */
  bool operator==(const Point &other) const {
    return (x == other.x && y == other.y);
  }
};

class Visualization {

    public:
    /**
     * @brief Construtor for visualization
     * @param airportfile - filename of airports data
     * @param routefile - filename of airlies data
     */
    Visualization(string airportfile, string routefile);

    /**
     * @brief draw the point of all the airports in the map.
     * @param image - image to be drawn on
     */
    void drawAirport(PNG& image);

    /**
     * @brief draw airlines between two airports.
     * @param source - source airport
     * @param destination - destination airport
     * @param framecount - the number of frames
     * @param image - image to be drawn on
     */
    void drawAirline(Airport source, Airport destination, int& framecount, PNG& image);

    /**
     * @brief draw the shortest path between source and destination.
     * @param source - source airport
     * @param destination - destination airport
     * @param file - the name of the image to be stored
     */
    void drawShortest(Airport source, Airport destination, string file);

    /**
     * @brief draw all the airlines in the data
     * @param file1 - the name of the generated png
     * @param file2 - the name of the generated gif
     */
    void drawAllAirlines(string file1, string file2);

    /**
     * @brief play the animation 
     * @param file - the name of the generated gif
     */
    void play(string file);

     /**
     * @brief add sourceicon and desticon on the image 
     * @param sourcepoint - the coordinate of the source airport
     * @param destpoint - the coordinate of the destination airport
     * @param image - where the sourceicon and desticon should be labeled
     */
    void addicon(Point sourcepoint, Point destpoint, PNG& image);
    
    /**
     * @brief helper functions for converting the longitude and latitude to the coordinate
     * @param airport -the subject to be converted
     */
    Point convert(Airport airport);


    /**
     * @brief draw a line between source and destination on the map without animation
     * @param sour - the coordinate of source airport
     * @param dest - the coordinate of destination airport
     * @param image - the image to be edited
     */
    void drawallhelper(Point sour, Point dest, PNG& image);

    /**
     * @brief producing animation for bfs algorithm
     * @param a - the airport to be plot in the image
     * @param animation - animation stored
     * @param image - the image to be edited
     */
    void AnimateBFS(Airport a, Animation& animation, PNG& image);

    /**
     * @brief helper function for sort airport by its name
     * @param name - the name of the airport
     */
    Airport sortbyName(string name) {
      Airport find = Airport();
      for (auto it : airportgraph) {
        if (it.first.name == name) find = it.first;
      }
      return find;
    }

    /**
     * @brief get a vector that contains the airline of the shortest path between source and destination
     * @param sour - source airport
     * @param dest - destination airport
     */
    vector<string> getAirline(Airport sour, Airport dest) {
      Airline airline;
      vector<string> toreturn;
      Dijkstra paths(graph, sour);
      vector<Airport> path = paths.shortestPath(dest);
      for (unsigned i = 0; i < path.size() - 1; i++) {
          Airport a = path[i];
          Airport b = path[i+1];
          for (auto it : airportgraph) {
            if (it.first == a) {
              for (auto i : it.second) {
                if (i.first == b) {
                  toreturn.push_back(i.second.label);
                }
              }
            }
          }
      }
      return toreturn;
    }
    private:

    //store the open.png here
    PNG background; 

    //store the airportgraph
    AirportGraph graph;
    map<Airport, map<Airport, Airline>> airportgraph;


    //colors for point, border and airline
    const cs225::HSLAPixel p = cs225::HSLAPixel(355, 100, 26, 1);
    const cs225::HSLAPixel border = cs225::HSLAPixel(355, 100, 26, 1);
    const cs225::HSLAPixel airline = cs225::HSLAPixel(100, 1, 0.5, 1);

    const int speed = 10;

    /*
      @param w - width of background
      @param h - height of background
    */
    int w;
    int h;
    
    //match Airport and its coordinated on the image
    map<Airport, Point> locations;

    vector<Airline> allroutes;

    //final animation
    Animation animation_;

    /**
     * @brief helper function for updating the airport and coordinate pair in locations 
     */
    void updateLocations();

    


    /**
     * @brief draw a border around the point to be more visible
     * @param point - the point to be added border
     * @param image - the image to be edited
     */
    void drawBorder(Point point, PNG& image);

     /**
     * @brief draw a line between source and destination on the map with animation
     * @param sour - the coordinate of source airport
     * @param dest - the coordinate of destination airport
     * @param framecount - the number of frames here
     * @param image - the image to be edited
     */
    void drawLine(Point sour, Point dest, int& framecount, PNG& image);

    
};
