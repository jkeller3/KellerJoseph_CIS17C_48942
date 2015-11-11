/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Assignment: 4
 * Created on October 20, 2015, 5:05 PM
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"
#include "Node.h"
using namespace std;

int main(int argc, char** argv) {
    Node* head = new Node;
    head->next=0;
    head->x=5;
    
    Node* tail = new Node;
    head->next=tail;
    tail->next=0;
    tail->x=6;
    
    Node* mid = new Node;
    head->next=mid;
    mid->next=tail;
    mid->x=2;
    
    cout<<"Head "<<head->x<<" ";
    cout<<head->next->x<<" ";
    cout<<head->next->next->x<<" Tail.\n";
    
    int num;
    do{
    cout<<"Type 1 to push, 2 to pull:\n";
    cin>>num;
    }while(num>2||num<1);
    
    SimpleVector v;
    if(num==1){
        cout<<"What number would you like to add?\n";
        int pushNum;
        cin>>pushNum;
        v.pushNode(pushNum);
    }
    
    if(num==2){
        v.pullNode();
    }

    return 0;
}

