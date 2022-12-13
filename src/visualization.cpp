#include "visualization.h"


Visualization::Visualization(string airportfile, string routefile) {
    graph = AirportGraph(airportfile, routefile);
    airportgraph = graph.getMap();
    background.readFromFile("../tests/open.png");
    w = background.width();
    h = background.height();
    updateLocations();
    
    for (auto it : airportgraph) {
        for (auto i : it.second) {
            allroutes.push_back(i.second);
            
        }
    }
    
}


void Visualization::updateLocations() {
    for (auto it : airportgraph) {
        Airport airp = it.first;
        if (locations.find(airp) == locations.end())
            locations[airp]  = convert(airp);
    }
}

Point Visualization::convert(Airport airport) {
    double latitude = airport.latitude;
    double longitude = airport.longitude;
    int x = round(w/360.0 * (180+longitude)) ;
    int y = round(h/180.0 *(latitude*(-1) + 90));
    if (x <= 0) x = 1;
    if (y <= 0) y = 1;
    if (x >= w) x = w-1;
    if (y >= h) y = h -1;
    Point p(x,y);
    return p;
}



void Visualization::drawBorder(Point point, PNG& image) {
   /* check lower bounds */
    if (point.x > 1) {
        image.getPixel(point.x - 1, point.y) = border;
        image.getPixel(point.x-2, point.y) = border;

    }
    if (point.y > 1) {
        image.getPixel(point.x, point.y - 1) = border;
        image.getPixel(point.x, point.y - 2) = border;
    }

    /* check upper bounds */
    if (point.x < (int) image.width() - 2) {
        image.getPixel(point.x + 1, point.y) = border;
        image.getPixel(point.x + 2, point.y) = border;
    }
    if (point.y < (int) image.height() - 2) {
        image.getPixel(point.x, point.y + 1) = border;
        image.getPixel(point.x, point.y + 2) = border;
    }
}

void Visualization::drawAirport(PNG& image) {
    for (auto it : locations) {
        Point point = it.second;
        image.getPixel(point.x, point.y) = p;
        
        drawBorder(point, image);
    }
}

void Visualization::drawAirline(Airport source, Airport destination, int& framecount, PNG& image) {
    Point sour = locations[source];
    Point dest = locations[destination];

    drawLine(sour, dest, framecount, image);

}
void Visualization::drawShortest(Airport source, Airport destination, string file) {
    int framecount = 0;
    PNG airport(background);
    Dijkstra paths(graph, source);
    vector<Airport> path = paths.shortestPath(destination);

    drawAirport(airport);

    Point s = locations[source];
    Point d = locations[destination];

    addicon(s,d,airport);

    for (unsigned i = 0; i < path.size() -1; i++) {
        Airport sour = path[i];
        Airport dest = path[i + 1];
        drawAirline(sour, dest, framecount, airport);

        if (framecount % speed != 0) animation_.addFrame(PNG(airport));
        framecount = 0;
    }
   

  

    airport.writeToFile("../images/" + file);
}
void Visualization::drawAllAirlines(string file1, string file2) {
    PNG all(background);
    drawAirport(all);

    Animation allairlines;
    allairlines.addFrame(all);
    int count = 0;
    for (unsigned i = 0; i < allroutes.size(); i++) {
        Airline airline = allroutes[i];
        Airport source = airline.source;
        Airport dest = airline.destination;
        Point s = locations[source];
        Point y = locations[dest];
        
        drawallhelper(s,y,all);
        if (allroutes.size() < 10) allairlines.addFrame(all);
        else if (allroutes.size() > 10 && allroutes.size() < 100) {
            if (count % 10 == 0) allairlines.addFrame(all);
        } 
        else  if (allroutes.size() > 100 && allroutes.size() < 5000){
            if (count % 500 == 0) allairlines.addFrame(all);
        }
        else {
            if (count % 5000 == 0) allairlines.addFrame(all);
        }
        
        count++;
        
    }
    
    all.writeToFile("../images/" + file1);
    allairlines.write("../images/" + file2);
}






void  Visualization::drawLine(Point sour, Point dest, int& framecount, PNG& image) {
    // Learn from the DDA line drawing algorithm
    double x1 = sour.x, x2 = dest.x, y1 = sour.y, y2 = dest.y; 
    double dx, dy;
    int wi = image.width();
    int hi = image.height();
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    //caltulate distance from point to point in normal
    double dis = sqrt(dx * dx + dy * dy);

    //check whether there is an greate circle right here
    double gcx1 = x1, gcx2 = x2;
    if (x1 <= x2) gcx2 = gcx2 - wi;
    else gcx1 = gcx1 - wi;
    double gcdx = gcx2 - gcx1;

    //calculate distance for great circle 
    double gcdis = sqrt(gcdx * gcdx + dy * dy);

    //check whether the distance for great circle is smaller
    if (gcdis <= dis){
        dx = gcdx;
        x1 = gcx1;
        x2 = gcx2;
    }
    
    int steps;
    //check whether the slope will be less than 1
    if (dx > dy) steps = dx;
    else steps = dy;
    

    //calculate the x and y dimension increments
    double xinc = dx / steps;
    double yinc = dy / steps;
    
    if (x1 >= x2 && y1 >= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 -= xinc;
            y1 -= yinc;
            if (framecount % speed == 0) {
                PNG tmp(image);
                animation_.addFrame(tmp);
            }
            framecount++;
        }
    }
    else if (x1 >= x2 && y1 <= y2){
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 -= xinc;
            y1 += yinc;
            if (framecount % speed == 0) {
                PNG tmp(image);
                animation_.addFrame(tmp);
            }
            framecount++;
        }
    }
    else if (x1 <= x2 && y1 >= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 += xinc;
            y1 -= yinc;
            if (framecount % speed == 0) {
                PNG tmp(image);
                animation_.addFrame(tmp);
            }
            framecount++;
        }
    }
    else if (x1 <= x2 && y1 <= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 += xinc;
            y1 += yinc;
            if (framecount % speed == 0) {
                PNG tmp(image);
                animation_.addFrame(tmp);
            }
            framecount++;
        }
    }
        

}   

void Visualization::drawallhelper(Point sour, Point dest, PNG& image) {
    // Learn from the DDA line drawing algorithm
    double x1 = sour.x, x2 = dest.x, y1 = sour.y, y2 = dest.y; 
    double dx, dy;
    int wi = image.width();
    int hi = image.height();
    dx = abs(x2-x1);
    dy = abs(y2-y1);

    //caltulate distance from point to point in normal
    double dis = sqrt(dx * dx + dy * dy);

    //check whether there is an greate circle right here
    double gcx1 = x1, gcx2 = x2;
    if (x1 <= x2) gcx2 = gcx2 - wi;
    else gcx1 = gcx1 - wi;
    double gcdx = gcx2 - gcx1;

    //calculate distance for great circle 
    double gcdis = sqrt(gcdx * gcdx + dy * dy);

    //check whether the distance for great circle is smaller
    if (gcdis <= dis){
        dx = gcdx;
        x1 = gcx1;
        x2 = gcx2;
    }
    
    int steps;
    //check whether the slope will be less than 1
    if (dx > dy) steps = dx;
    else steps = dy;
    

    //calculate the x and y dimension increments
    double xinc = dx / steps;
    double yinc = dy / steps;
    
    if (x1 >= x2 && y1 >= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 -= xinc;
            y1 -= yinc;
        }
    }
    else if (x1 >= x2 && y1 <= y2){
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 -= xinc;
            y1 += yinc;
        }
    }
    else if (x1 <= x2 && y1 >= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 += xinc;
            y1 -= yinc;
        }
    }
    else if (x1 <= x2 && y1 <= y2) {
        for (int i = 0; i < steps; i++){
            if (x1 > 0 && x1 < w && y1 > 0 && y1 < h)
                image.getPixel((unsigned) x1, (unsigned)(round(y1))) = airline;
            x1 += xinc;
            y1 += yinc;
        }
    }

}
    


void Visualization::play(string file) {
    animation_.write("../images/" + file);
}

void Visualization::addicon(Point sourcepoint, Point destpoint, PNG& image) {
    PNG sourceicon;
    PNG desticon;

    sourceicon.readFromFile("../tests/sourceicon.png");
    desticon.readFromFile("../tests/desticon.png");

    int s_x = sourceicon.width();
    int s_y = sourceicon.height();
    int half_sx = s_x/2;
    int half_sy = s_y/2;

    int start_x = sourcepoint.x - half_sx;
    int start_y = sourcepoint.y - half_sy;
    for (int i = 0; i < s_x; i++) {
        for (int j = 0; j < s_y; j++) {
            image.getPixel(start_x + i, start_y + j) = sourceicon.getPixel(i,j);
        }
    }
    
    
    int d_x = desticon.width();
    int d_y = desticon.height();
    int half_dx = d_x/2;
    int half_dy = d_y/2;

    int end_x = destpoint.x - half_dx;
    int end_y = destpoint.y - half_dy;
    for (int i = 0; i < d_x; i++) {
        for (int j = 0; j < d_y; j++) {
            image.getPixel(end_x + i, end_y + j) = desticon.getPixel(i,j);
        }
    }
    

}


void Visualization::AnimateBFS(Airport a, Animation& animation, PNG& image) {
    Point point = locations[a];
    image.getPixel(point.x, point.y) = p;
    drawBorder(point, image);
    animation.addFrame(image);
}