/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 14, 2015, 4:52 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "AdjListNode.h"
#include "AdjList.h"
#include "Graph.h"

int main(int argc, char** argv) {
    Graph gh(6);
    gh.AddEdge(0, 1, 2);
    gh.AddEdge(1, 2, 4);
    gh.AddEdge(2, 3, 1);
    gh.AddEdge(3, 4, 3);
    gh.AddEdge(4, 5, 7);
    gh.AddEdge(5, 0, 5);

 
    // print the adjacency list representation of the above graph
    gh.PrintGraph();
    
    int input;
    int curr = 0;
    do{
        gh.Print(curr);
        cout<<"Which point would you like to move to?\n";
        cout<<"Enter -1 to exit.\n";
        cin>>input;
        curr=gh.Traverse(curr,input);
    }while(input!=-1);
    
    cout<<"Between which two points would you like to find the minimum distance?\n";
    int start,end;
    cin>>start;
    cin>>end;
    gh.MinimumSpanningTree(start,end);

    return 0;
}

