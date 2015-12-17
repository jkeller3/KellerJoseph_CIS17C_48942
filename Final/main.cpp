/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 16, 2015, 5:51 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Hashing.h"
#include "Queues.h"
#include "Stacks.h"
#include "Sorting.h"
#include "BinaryTrees.h"
#include "WeightedGraphs.h"

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
                sort.HeapSort();
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
    graph.addEdge("SFO","BOS",2704);
    graph.addEdge("SFO","ORD",1846);
    graph.addEdge("ORD","BOS",867);
    graph.addEdge("ORD","JFK",740);
    graph.addEdge("JFK","BOS",187);
    graph.addEdge("SFO","DFW",1464);
    graph.addEdge("DFW","ORD",802);
    graph.addEdge("DFW","MIA",1121);
    graph.addEdge("MIA","JFK",1090);
    graph.addEdge("MIA","BOS",1258);
    graph.addEdge("SFO","LAX",337);
    graph.addEdge("LAX","DFW",1235);
    graph.addEdge("LAX","MIA",2342);
}

void def(int inN){
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
} 