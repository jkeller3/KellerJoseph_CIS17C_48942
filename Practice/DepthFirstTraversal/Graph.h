// C++ program to print DFS traversal from a given vertex in a given graph
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>

// Graph class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS(int v);    // DFS traversal of the vertices reachable from v
};

#endif /* GRAPH_H */

