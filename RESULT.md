# Result

# Contributor
Fred Hou (zhengqi5)

Carmen Zheng (dingnan2)

Junhan Chen (junhanc2)

Jason Zhang (zijie3)

# BFS Algorithm
We use BFS algorithm to traverse the graph, and this algorithm is able to visit every node in the graph, returning an animation that represents the process of traversing each node. 

We provide several test cases for this algorithm, which are in the **test_bfs.cpp**. We can run **make test** and **./test** to see whether this algorithm is running well. 

The result is shown in the images file called bfs50.gif.


# Dijkstra's Algorithm

We use Dijkstra's algorithm to find the shortest path between two airports. It can traverse from the starting point and return the shortest path to the other nodes. 

We provide several test cases for this algorithm, which are in the **test_bfs.cpp**. We can run **make test** and **./test** to see whether this algorithm is running well. 

The result is shown in the images file called shortest50.gif.


# Conclusion

By completing all of the code, we can successfully find the shorest path between two airports, and visualize it in the world map picture.

We have made two systems to visualize our works: one is visualizing routes on png and gif, the other is a command located in main that take the name of source airport and destination airport and later auto generated the result.