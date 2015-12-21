/* 
 * File:   WeightedGraphs.cpp
 * Author: rcc
 * 
 * Created on December 16, 2015, 5:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "WeightedGraphs.h"
using namespace std;
WeightedGraphs::WeightedGraphs(int v){
    this->v = v;
    array = new AdjList [this->v];
    for (int i = 0; i < this->v; ++i)
        array[i].head = NULL;
}

AdjListNode* WeightedGraphs::NewAdjListNode(string name, string dest, int dist, int index){
    AdjListNode* newNode = new AdjListNode;
    newNode->name = name;
    newNode->dest = dest;
    newNode->dist = dist;
    newNode->destIndex = index;
    newNode->next = NULL;
    return newNode;
}

WeightedGraphs::~WeightedGraphs(){
    
}

int WeightedGraphs::GetIndex(string airport){
    if(airport=="SFO")
        return 0;
    else if(airport=="BOS")
        return 1;
    else if(airport=="LAX")
        return 2;
    else if(airport=="ORD")
        return 3;
    else if(airport=="JFK")
        return 4;
    else if(airport=="DFW")
        return 5;
    else
        return 6;
}

void WeightedGraphs::AddEdge(string src, string dest, int dist){
    int index1 = GetIndex(src);
    int index2 = GetIndex(dest);
    AdjListNode* newNode = NewAdjListNode(src,dest,dist,index2);
    newNode->next = array[index1].head;
    array[index1].head = newNode;
    newNode = NewAdjListNode(dest,src,dist,index1);
    newNode->next = array[index2].head;
    array[index2].head = newNode;
}

int WeightedGraphs::Traverse(int curr, int trav){
    AdjListNode* pCrawl = array[curr].head;
    while (pCrawl){
        if(pCrawl->destIndex == trav){
            return trav;
        }
        pCrawl=pCrawl->next;
    }
    return curr;
}

void WeightedGraphs::SortEdges(){
    for(int i=0; i<7; i++){
        AdjListNode* pCrawl = array[i].head;
        AdjListNode* node = pCrawl;
        pCrawl=pCrawl->next;
        while(pCrawl){
            if(pCrawl->dist < node->dist){
                AdjListNode* temp = pCrawl->next;
                pCrawl->next = node;
                node->next = temp;
                pCrawl=array[i].head;
                node=pCrawl;
                pCrawl=pCrawl->next;
            }
            node=node->next;
            pCrawl=pCrawl->next;
        }
    }
}

//void WeightedGraphs::MinimumSpanningTree(int start){
//    bool* checked = new bool [7];
//    bool allChecked=false;
//    for(int i=0; i<7; i++)
//        checked[i]=false;
//    checked[start]=true;
//    AdjListNode* pCrawl = array[start].head;
//    AdjListNode* qCrawl = pCrawl;
//    pCrawl = pCrawl->next;
//    while(allChecked==false){
//        if(pCrawl->dist > qCrawl-> dist){
//            
//        }
//    }
//}
//    if(start>7||start<0||end>7||end<0)
//        return;
//    int total1 = 0;
//    int total2 = 0;
//    int trav = start;
//    AdjListNode* pCrawl = array[trav].head;
//    while(trav!=end){
//        if(trav==0){
//            trav=5;
//        } else{
//            trav--;
//        }
//        pCrawl=array[trav].head;
//        total1+=pCrawl->dist;
//    }
//    trav=start;
//    pCrawl = array[trav].head;
//    while(trav!=end){
//        if(trav==5){
//            trav=0;
//        } else{
//            trav++;
//        }
//        pCrawl=array[trav].head;
//        total2+=pCrawl->dist;
//    }
//    trav=start;
//    if(total1>total2){
//        printf("The shortest path is: ");
//        pCrawl = array[trav].head;
//        while(trav!=end){
//            if(trav==0){
//                printf("(%d, %d),",trav,5);
//                trav=5;
//            } else{
//                printf("(%d, %d),",trav, trav-1);
//                trav--;
//            }
//            pCrawl=array[trav].head;
//        }
//    } else if(total2>total1){
//        printf("The shortest path is: ");
//        pCrawl = array[trav].head;
//        while(trav!=end){
//            if(trav==5){
//                printf("(%d, %d),",trav,0);
//                trav=0;
//            } else{
//                printf("(%d, %d),",trav, trav+1);
//                trav++;
//            }
//            pCrawl=array[trav].head;
//        }
//    }
//}

void WeightedGraphs::Print(int curr){
    AdjListNode* pCrawl = array[curr].head;
    printf("\nAdjacency list of vertex %d) %s\n head",curr,array[curr].head->name.c_str());
    while(pCrawl){
        printf(" -> %d)%s (%d)",pCrawl->destIndex,pCrawl->dest.c_str(),pCrawl->dist);
        pCrawl=pCrawl->next;
    }
    printf("\n");
    ShortestDistance(curr);
}

void WeightedGraphs::ShortestDistance(int curr){
    AdjListNode* pCrawl = array[curr].head;
    string shortDest = pCrawl->dest;
    int shortDist = pCrawl->dist;
    pCrawl=pCrawl->next;
    while(pCrawl){
        if(pCrawl->dist < shortDist){
            shortDest = pCrawl->dest;
            shortDist = pCrawl->dist;
        }
        pCrawl=pCrawl->next;
    }
    printf("The shortest destination is %s with a distance of %d.\n",shortDest.c_str(),shortDist);
}

void WeightedGraphs::PrintGraph(){
    int v;
    for (v = 0; v < this->v; v++){
        AdjListNode* pCrawl = array[v].head;
        printf("Adjacency list of vertex %d) %s\n head",v,array[v].head->name.c_str());
        while (pCrawl){
            printf(" -> %s",pCrawl->dest.c_str());
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}