/* 
 * File:   main.cpp
 * Author: joey
 *
 * Created on December 12, 2015, 2:14 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Graph.h"

/*
 * 
 */
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}