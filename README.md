# Shortest Path Between Two Airports

# Intro

> Code Storing place

**airline.h & airport.h:** contains two classes: Airline and Airport. They contains variables essential for graph building. The airport class represents the node in the graph and the airline class represents the edge conneced two nodes.

**airportgraph.h & airportgraph.cpp:** including the graph building by mutable map. Also contains data pasrsing and converting to graph.

**bfs.h** contains bfs algorithm and generate a gif stored in images file for the process of bfs traversal

**dijkstra.cpp & dijkstra.h:** contains the dijkstra's algorithm and betweeness centrality. Both works for finding the optmal shortest path between source airport and destination airport

**visualization.cpp & visualization.h:**  with the implementation of animation library, visualizing the result of data parsing, graph building and dijkstra's algorithm for finding the shortest path. The generated images will be stored in the images file.



> Test storing place

**tests**

Contains test case for graph, data parsing, bfs algorithm, dijkstra's algorithm and visualization.
At the same time, it stores the some sample data csv for airpots and airlines  that will be used in the test cases. 

**data**
It stores two files: data for all the airports, and data for all the airlines.

> Images storing place

**Images:** Storing all the images generated from visualization test cases and main command.

# Running Instructions

> Running Instruction

Put the **cs225_final_project_flights** folder in to your cs225 development folder. Open the terminal on the root directory and type the following commands:

$ mkdir build

$ cd build

$ cmake..

$ make

> Test Cases Running

The envrionment is built based on the cmakelist from cs225 and we utilize the docker file containers. 
After building the build file and running the command **cmake ..**, we are able to run the test by the command **make test** and **./test** for all the test cases written.
