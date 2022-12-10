#pragma once
#include <string>
#include "airport.h"

using std::string;

class Airline {

  public:
    Airport source;
    Airport destination;
    double weight;
    string label;

    /**
     * @brief Default constructor.
     */
    Airline() : weight(-1), label("") { 
      // nothing
    }

    /**
     * @brief Parameter constructor for airlines.
     * @param sc - one airport of an airline
     * @param dest - the other airport of an airline
     * @param wei - airline distance
     * @param lbl - airline name
     */
    Airline(Airport sc, Airport dst, double wei, string lbl)
      : source(sc), destination(dst), weight(wei), label(lbl) {
        // nothing
    }

    /**
     * @brief Compare two airlines.
     * @param other - the airline to compare with
     * @return whether the current airline is shorter than the parameter airline
     */
    bool operator<(const Airline& other) const
    {
        return label < other.label;
    }

    /**
     * @brief Compare source and destination.
     * @param other - the airline to compare with
     */
    bool operator==(Airline& other) const
    {
        if (!(this->source == other.source))
            return false;
        if (!(this->destination == other.destination))
            return false;
        return true;
    }

};