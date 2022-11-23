#include <string>

using std::string;

class Vertex {
  
  public:
    string name; 
    string ID;
    double latitude;
    double longitude;

    /**
     * Default constructor.
     */
    Vertex() : name(""), ID(""), latitude(-1), longitude(-1) { 
      // nothing
    }

    /**
     * Parameter constructor for vertices
     * @param nm - airport's name
     * @param id - airport's id
     * @param lat - airport's latitude
     * @param lon - airport's longitude
     */
    Vertex(string nm, string id, double lat, double lon)
      : name(nm), ID(id), latitude(lat), longitude(lon) {
        // nothing
    }

    /**
     * Compares two vertices
     * @param other - the vertex to compare with
     */
    bool operator==(Vertex& other) const
    {
        if (this->name != other.name)
            return false;
        if (this->ID != other.ID)
            return false;
        return true;
    }

};