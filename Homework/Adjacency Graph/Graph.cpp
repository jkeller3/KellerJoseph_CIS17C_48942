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

AdjListNode* Graph::NewAdjListNode(int dest, int dist){
    AdjListNode* newNode = new AdjListNode;
    newNode->dest = dest;
    newNode->dist = dist;
    newNode->next = NULL;
    return newNode;
}

void Graph::AddEdge(int src, int dest, int dist){
    AdjListNode* newNode = NewAdjListNode(dest,dist);
    newNode->next = array[src].head;
    array[src].head = newNode;
    newNode = NewAdjListNode(src,dist);
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

void Graph::MinimumSpanningTree(int start, int end){
    if(start>5||start<0||end>5||end<0)
        return;
    int total1 = 0;
    int total2 = 0;
    int trav = start;
    AdjListNode* pCrawl = array[trav].head;
    while(trav!=end){
        if(trav==0){
            trav=5;
        } else{
            trav--;
        }
        pCrawl=array[trav].head;
        total1+=pCrawl->dist;
    }
    trav=start;
    pCrawl = array[trav].head;
    while(trav!=end){
        if(trav==5){
            trav=0;
        } else{
            trav++;
        }
        pCrawl=array[trav].head;
        total2+=pCrawl->dist;
    }
    trav=start;
    if(total1>total2){
        printf("The shortest path is: ");
        pCrawl = array[trav].head;
        while(trav!=end){
            if(trav==0){
                printf("(%d, %d),",trav,5);
                trav=5;
            } else{
                printf("(%d, %d),",trav, trav-1);
                trav--;
            }
            pCrawl=array[trav].head;
        }
    } else if(total2>total1){
        printf("The shortest path is: ");
        pCrawl = array[trav].head;
        while(trav!=end){
            if(trav==5){
                printf("(%d, %d),",trav,0);
                trav=0;
            } else{
                printf("(%d, %d),",trav, trav+1);
                trav++;
            }
            pCrawl=array[trav].head;
        }
    }
}

void Graph::Print(int curr){
    AdjListNode* pCrawl = array[curr].head;
    printf("\nAdjacency list of vertex %d\n head",curr);
    while(pCrawl){
        printf(" -> %d (%d)",pCrawl->dest,pCrawl->dist);
        pCrawl=pCrawl->next;
    }
    printf("\n");
    ShortestDistance(curr);
}

void Graph::ShortestDistance(int curr){
    AdjListNode* pCrawl = array[curr].head;
    int shortDest = pCrawl->dest;
    int shortDist = pCrawl->dist;
    pCrawl=pCrawl->next;
    while(pCrawl){
        if(pCrawl->dist < shortDist){
            shortDest = pCrawl->dest;
            shortDist = pCrawl->dist;
        }
        pCrawl=pCrawl->next;
    }
    printf("The shortest destination is %d with a distance of %d.\n",shortDest,shortDist);
}

void Graph::PrintGraph(){
    int v;
    for (v = 0; v < this->v; v++){
        AdjListNode* pCrawl = array[v].head;
        printf("Adjacency list of vertex %d\n head",v);
        while (pCrawl){
            printf(" -> %d",pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}