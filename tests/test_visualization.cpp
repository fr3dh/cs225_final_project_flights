#include <catch2/catch_test_macros.hpp>
#include "visualization.h"


TEST_CASE("visualization sample size 4", "[visualization]") {
    Visualization visualization("../tests/airport.csv", "../tests/airline.csv");

    Airport kug = Airport("Kugaaruk Airport", "1", 68.5344, -89.8081);
    Airport baie = Airport("Baie Comeau Airport", "2" , 49.1325, -68.2044);
    Airport cfb = Airport("CFB Bagotville", "3", 48.3306, -70.9964);
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);

    string file = "drawsmall.png";
    PNG image;
    image.readFromFile("../tests/open.png");
    visualization.drawAirport(image);
    image.writeToFile("../images/" + file);
    string file2 = "shortestsmall.png";
    visualization.drawShortest(kug, baie, file2);
    
    string file3 = "allroute4.png";
    string file4 = "allroute4.gif";
    visualization.drawAllAirlines(file3, file4);

    string file1 = "playsmall.gif";
    visualization.play("../images/"+file1);

    

}

TEST_CASE("visualization sample size 50", "[visualization]") {
    Visualization visualization("../tests/airports50.csv", "../tests/airlines50.csv");

    Airport kazan = Airport("Kazan International Airport", "2990", 55.6062, 49.2787);
    Airport novy = Airport("Novy Urengoy Airport", "4364" , 66.0694, 76.5203);
    Airport baelgorod = Airport("Belgorod International Airport", "6156", 50.6438, 36.5901);
    Airport baker = Airport("Baker Lake Airport", "4" , 64.2989, -96.0778);

    string file = "drawairports50.png";
    PNG image;
    image.readFromFile("../tests/open.png");
    visualization.drawAirport(image);
    image.writeToFile("../images/" + file);

    string file2 = "shortest50.png";
    visualization.drawShortest(kazan, baelgorod, file2);
    
    string file3 = "allroute50.png";
    string file4 = "allroute50.gif";
    visualization.drawAllAirlines(file3, file4);

    string file1 = "play50.gif";
    visualization.play("../images/"+file1);
}

TEST_CASE("visualization sample size 1000 drawairport", "[visualization]") {
    Visualization visualization("../tests/airports1000.csv", "../tests/routes1000.csv");

    // Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
    // Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

    string file = "drawairport4000.png";
    PNG image;
    image.readFromFile("../tests/open.png");

    visualization.drawAirport(image);
    image.writeToFile("../images/" + file);
}

TEST_CASE("visualization sample size 1000 drawairline", "[visualization]") {
    Visualization visualization("../tests/airports1000.csv", "../tests/routes1000.csv");

    Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
    Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

    string file = "drawairline1000.png";
    PNG image;
    image.readFromFile("../tests/open.png");
    visualization.drawAirport(image);
    
    int count = 0;
    visualization.drawAirline(ohare, hk, count, image);
    Point oh = visualization.convert(ohare);
    Point h = visualization.convert(hk);
    visualization.addicon(oh, h, image);
    image.writeToFile("../images/" + file);

    string file2 = "drawAirline1000.gif";
    visualization.play(file2);
    
}

TEST_CASE("visualization sample size 1000 drawallhelper", "[visualization]") {
    Visualization visualization("../tests/airports1000.csv", "../tests/routes1000.csv");

    Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
    Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

    string file = "drawallhelper1000.png";
    PNG image;
    image.readFromFile("../tests/open.png");
    //visualization.drawAirport(image);
    
    
    
    Point oh = visualization.convert(ohare);
    Point h = visualization.convert(hk);
    visualization.addicon(oh, h, image);
    visualization.drawallhelper(oh, h, image);
    image.writeToFile("../images/" + file);
    
}

TEST_CASE("visualization sample size 1000 drawallairlines", "[visualization]") {
    Visualization visualization("../tests/airports1000.csv", "../tests/routes1000.csv");

    Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
    Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

    string file = "drawallairlines1000.png";
    string file1 = "drawallairlines1000.gif";
    PNG image;
    image.readFromFile("../tests/open.png");
    //visualization.drawAirport(image);
    
    
    
    Point oh = visualization.convert(ohare);
    Point h = visualization.convert(hk);
    visualization.addicon(oh, h, image);

    visualization.drawAllAirlines(file, file1);
    //image.writeToFile("../images/" + file);
    
}

// TEST_CASE("visualization all", "[visualization]") {
//     Visualization visualization("../data/airports.csv", "../data/routes.csv");

//     Airport hk = Airport("Hong Kong International Airport", "3077", 22.3089, 113.9150);
//     Airport ohare = Airport("Chicago O'Hare International Airport", "3830", 41.9786, -87.9048);

//     string file = "drawallairports.png";
//     PNG image;
//     image.readFromFile("../tests/open.png");
//     visualization.drawAirport(image);
//     image.writeToFile("../images/" + file);

//     // string file2 = "tohome.png";
//     // visualization.drawShortest(ohare, hk, file2);
    
//     string file3 = "allroutes.png";
//     string file4 = "allroutes.gif";
//     visualization.drawAllAirlines(file3, file4);

//     string file1 = "plays.gif";
//     visualization.play("../images/"+file1);


// }