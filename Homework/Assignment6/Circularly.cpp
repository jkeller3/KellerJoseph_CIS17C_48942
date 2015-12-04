/* 
 * File:   Circularly.cpp
 * Author: rcc
 * 
 * Created on December 2, 2015, 7:46 PM
 */

#include "Circularly.h"
#include <iostream>

Circularly::Circularly(){
//    head = new Node;
    tail = new Node;
//    head->next=NULL; 
    tail->prev=NULL; 
    listSize=0;
}

Circularly::Circularly(const Circularly& orig) {
    if(this != &orig){
//        head = orig.head;
        tail = orig.tail;
        listSize = orig.listSize;
    }
}

Circularly::~Circularly() {
    for(int i=0; i<listSize; i++){
        Node* temp = tail->next;
        delete tail;
        tail=temp;
    }
}

void Circularly::Push(int n){
    Node* push = new Node;
    push->x=n;
    if(listSize==0){
        tail=push;
        push->next=tail;
    }
    else{
        push->next=tail->next;
        tail->next=push;
    }
    listSize++;
}

void Circularly::Pop(){
    Node* temp = tail;
    if(tail==NULL) return;
    else{
        if(temp->next==NULL){
        tail=NULL;
        delete temp;
        listSize--;
        }
        else{
            tail = tail->next;
            delete temp;
            listSize--;
        }
    }
    
}

void Circularly::Print(){
    if(tail->next==NULL){
        std::cout<<"List is empty.\n";
        return;
    }
    Node* temp=tail;
    for(int i=0; i<listSize*2+1; i++){
        std::cout<<temp->x;
        std::cout<<" --> ";
        temp=temp->next;
    }
    std::cout<<"NULL\n";
}

