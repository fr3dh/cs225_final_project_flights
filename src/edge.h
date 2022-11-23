#include <string>
#include "vertex.h"

using std::string;

class Edge {

  public:
    Vertex source;
    Vertex destination;
    double weight;
    string label;

    /**
     * Default constructor.
     */
    Edge() : weight(-1), label("") { 
      // nothing
    }

    /**
     * Parameter constructor for edges
     * @param sc - one airport of an airline
     * @param dest - the other airport of an airline
     * @param wei - airline distance
     * @param lbl - airline name
     */
    Edge(Vertex sc, Vertex dst, double wei, string lbl)
      : source(sc), destination(dst), weight(wei), label(lbl) {
        // nothing
    }

    /**
     * Compares two airlines.
     * @param other - the airline to compare with
     * @return whether the current airline is shorter than the parameter airline
     */
    bool operator<(const Edge& other) const
    {
        return weight < other.weight;
    }

    /**
     * Compares source and destination.
     * @param other - the airport edge to compare with
     */
    bool operator==(Edge& other) const
    {
        if (!(this->source == other.source))
            return false;
        if (!(this->destination == other.destination))
            return false;
        return true;
    }

};