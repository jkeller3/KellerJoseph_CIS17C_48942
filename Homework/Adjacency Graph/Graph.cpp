/* 
 * File:   Graph.cpp
 * Author: rcc
 * 
 * Created on December 14, 2015, 4:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Graph::Graph(int v){
    this->v = v;
    array = new AdjList [this->v];
    for (int i = 0; i < this->v; ++i)
        array[i].head = NULL;
}

AdjListNode* Graph::NewAdjListNode(int dest,int dist){
    AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->dist = dist;
    newNode->next = NULL;
    return newNode;
}

void Graph::AddEdge(int src,int dest){
    int randNum = rand()%9+1;
    AdjListNode* newNode = NewAdjListNode(dest,randNum);
    newNode->next = array[src].head;
    array[src].head = newNode;
    newNode = NewAdjListNode(src);
    newNode->next = array[dest].head;
    array[dest].head = newNode;
}

int Graph::Traverse(int curr, int trav){
    AdjListNode* pCrawl = array[curr].head;
    while (pCrawl){
        if(pCrawl->dest == trav){
            return trav;
        }
        pCrawl=pCrawl->next;
    }
    return curr;
}

void Graph::Print(int curr){
    AdjListNode* pCrawl = array[curr].head;
    printf("\nAdjacency list of vertex %d\n head",curr);
    while(pCrawl){
        printf(" -> %d",pCrawl->dest);
        pCrawl=pCrawl->next;
    }
    printf("\n");
}

void Graph::PrintGraph(){
    int v;
    for (v = 0; v < this->v; ++v){
        AdjListNode* pCrawl = array[v].head;
        printf("Adjacency list of vertex %d\n head",v);
        while (pCrawl){
            printf(" -> %d",pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}