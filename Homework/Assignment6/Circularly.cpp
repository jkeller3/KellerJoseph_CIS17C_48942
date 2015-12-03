/* 
 * File:   Circularly.cpp
 * Author: rcc
 * 
 * Created on December 2, 2015, 7:46 PM
 */

#include "Circularly.h"

Circularly::Circularly(){
    head = new Node;
    tail = new Node;
    head->next=tail; 
    tail->prev=head; 
    listSize=0;
}

Circularly::Circularly(const Circularly& orig) {
    if(this != &orig){
        head = orig.head;
        tail = orig.tail;
        listSize = orig.listSize;
    }
}

Circularly::~Circularly() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
}

void Circularly::Push(int n){
    Node* push = new Node;
    push->x=n;
    if(listSize==0){
        push->prev=NULL;
        head=push;
    }
    else{
        push->prev=tail;
        tail->next=push;
    }
    tail=push;
    listSize++;
}

void Circularly::Print(){
    if(head->next==NULL){
        std::cout<<"List is empty.\n";
        return;
    }
    Node* temp=head;
    std::cout<<"Head to tail: ";
    while (temp!=NULL){
        std::cout<<temp->x;
        std::cout<<" --> ";
        temp=temp->next;
    }
    std::cout<<"NULL\n";
    Node* temp2=tail;
    std::cout<<"Tail to head: ";
    while (temp2!=NULL){
        std::cout<<temp2->x;
        std::cout<<" --> ";
        temp2=temp2->prev;
    }
    std::cout<<"NULL\n";
}

