/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 16, 2015, 5:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Hashing.h"
#include "Queues.h"
#include "Stacks.h"
#include "Sorting.h"
#include "BinaryTrees.h"
#include "WeightedGraphs.h"
#include "AdjListNode.h"
#include "AdjList.h"

void menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void def(int);

int main(int argc, char** argv) {
    int inN;
    do{
        menu();
        inN=getN();
        switch(inN){
            case 1:
                problem1();
                break;
            case 2:
                problem2();
                break;
            case 3:
                problem3();
                break;
            case 4:
                problem4();
                break;
            case 5:
                problem5();
                break;
            case 6:
                problem6();
                break;
            default:
                def(inN);
        }    
    }while(inN>0);
    return 0;
}

void menu(){
    cout<<"Type 1 for Problem 1\n";
    cout<<"Type 2 for Problem 2\n";
    cout<<"Type 3 for Problem 3\n";
    cout<<"Type 4 for Problem 4\n";
    cout<<"Type 5 for Problem 5\n";
    cout<<"Type 6 for Problem 6\n";
    cout<<"Type 0 to exit\n";
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}

void problem1(){
    Hashing hash;
    ifstream myfile;
    myfile.open("nameslist.txt");
    while(!myfile.eof()){
        char* initials = new char[3];
        myfile.getline(initials,sizeof(myfile));
        hash.Hash(initials);
        delete initials;
    }
    myfile.close();
    hash.Print();
}

void problem2(){
    Stacks stack;
}

void problem3(){
    Queues queue;
}

void problem4(){
    Sorting sort;
    int inN;
    do{
        sort.Menu();
        inN=getN();
        switch(inN){
            case 1:
                sort.FillList();
                sort.BubbleSort();
                sort.PrintTop();
                break;
            case 2:
                sort.FillList();
                sort.SelectionSort();
                sort.PrintTop();
                break;
            case 3:
                sort.FillList();
                sort.MergeSort();
                sort.PrintTop();
                break;
            case 4:
                sort.FillList();
                sort.QuickSort(0,99999);
                sort.PrintTop();
                break;
            case 5:
                sort.FillList();
                sort.Build();
                sort.PrintTop();
                break;
            default:
                def(inN);
        }    
    }while(inN>0);
    
}

void problem5(){
    BinaryTrees tree;
}

void problem6(){
    WeightedGraphs graph(7);
    graph.AddEdge("SFO","BOS",2704);
    graph.AddEdge("SFO","ORD",1846);
    graph.AddEdge("ORD","BOS",867);
    graph.AddEdge("ORD","JFK",740);
    graph.AddEdge("JFK","BOS",187);
    graph.AddEdge("SFO","DFW",1464);
    graph.AddEdge("DFW","ORD",802);
    graph.AddEdge("DFW","MIA",1121);
    graph.AddEdge("MIA","JFK",1090);
    graph.AddEdge("MIA","BOS",1258);
    graph.AddEdge("SFO","LAX",337);
    graph.AddEdge("LAX","DFW",1235);
    graph.AddEdge("LAX","MIA",2342);
    graph.SortEdges();
    graph.PrintGraph();
    
    int input;
    int curr = 0;
    do{
        graph.Print(curr);
        cout<<"Which point would you like to move to?\n";
        cout<<"Enter -1 to exit.\n";
        cin>>input;
        curr=graph.Traverse(curr,input);
    }while(input!=-1);
//    cout<<"Between which two points would you like to find the minimum distance?\n";
//    int start,end;
//    cin>>start;
//    cin>>end;
//    graph.MinimumSpanningTree(start,end);
}

void def(int inN){
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 