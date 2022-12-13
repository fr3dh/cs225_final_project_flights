#include <iostream>
#include "visualization.h"

using namespace std;
int main() {
    string sourname, destname;
    char s[1000];
    cout << "Enter the source airport: " << endl;
    getline(cin, sourname);

    // for (int i = 0; i < 1000; i++) sourname +=s[i];
    
    char d[1000];
    cout << "Enter the destination airport: " << endl;
    
    getline(cin, destname);
    
    // for (int i = 0; i < 1000; i++) destname +=d[i];

    cout << "your source airport: " << sourname << ", your destination airport: " << destname << endl;
    Visualization visualization = Visualization("../tests/airports50.csv", "../tests/airlines50.csv");
    Airport sour = visualization.sortbyName(sourname);
    Airport dest = visualization.sortbyName(destname);

   
    PNG image;
    image.readFromFile("../tests/open.png");
    visualization.drawAirport(image);
    

    string file2 = "your.png";
    visualization.drawShortest(sour, dest, file2);

    string file = "your.gif";
    visualization.play(file);

    vector<string> result = visualization.getAirline(sour, dest);
    if (result.size() == 0) {
      cout << "sorry, there is no airline between" << endl;
      return 0;
    }
    cout << "you can take airline: ";
    for (auto it : result) {
      cout << it << "   ";
    }
    cout << " for the trip." << endl;

    cout<< "your route map is generated in images file." << endl;

    return 0 ;
}