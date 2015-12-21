/* 
 * File:   WeightedGraphs.h
 * Author: rcc
 *
 * Created on December 16, 2015, 5:57 PM
 */

#ifndef WEIGHTEDGRAPHS_H
#define	WEIGHTEDGRAPHS_H
#include <string>
#include "AdjListNode.h"
#include "AdjList.h"
using namespace std;
class WeightedGraphs {
private:
    int v;
    AdjList* array;

public:
    WeightedGraphs(int);
    WeightedGraphs(const WeightedGraphs& orig);
    virtual ~WeightedGraphs();
    int GetIndex(string);
    AdjListNode* NewAdjListNode(string,string,int,int);
    void AddEdge(string,string,int);
    int Traverse(int,int);
    void SortEdges();
    void MinimumSpanningTree(int);
    void Print(int);
    void ShortestDistance(int);
    void PrintGraph();
};

#endif	/* WEIGHTEDGRAPHS_H */

