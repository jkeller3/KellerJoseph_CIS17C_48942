/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Assignment: 4
 * Created on October 20, 2015, 5:05 PM
 */

#include <cstdlib>
#include <iostream>
#include "SimpleVector.h"
#include "node.h"
using namespace std;

int main(int argc, char** argv) {
    Node* head = new node;
    head->next=0;
    head->x=5;
    
    Node* tail = new node;
    head->next=tail;
    tail->next=0;
    tail->x=6;
    
    node* mid = new node;
    head->next=mid;
    mid->next=tail;
    mid->x=2;
    
    cout<<"Head "<<head->x<<" ";
    cout<<head->next->x<<" ";
    cout<<head->next->next->x<<" Tail.\n";

    return 0;
}

