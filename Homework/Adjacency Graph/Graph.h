/* 
 * File:   Graph.h
 * Author: rcc
 *
 * Created on December 14, 2015, 4:54 PM
 */

#ifndef GRAPH_H
#define	GRAPH_H
#include "AdjListNode.h"
#include "AdjList.h"

class Graph{
private:
    int v;
    struct AdjList* array;
public:
    Graph(int);
    Graph(const Graph& orig);
    virtual ~Graph(){};
    AdjListNode* NewAdjListNode(int,int);
    void AddEdge(int,int);
    int Traverse(int,int);
    void Print(int);
    void PrintGraph();
};

#endif	/* GRAPH_H */

