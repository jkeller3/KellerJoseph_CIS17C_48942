/* 
 * File:   Doubly.cpp
 * Author: rcc
 * 
 * Created on December 2, 2015, 6:35 PM
 */

#include "Doubly.h"
#include <iostream>

Doubly::Doubly(){
    head = new Node;
    tail = new Node;
    head->next=tail; 
    tail->prev=head; 
    listSize=0;
}

Doubly::Doubly(const Doubly& orig) {
    if(this != &orig){
        head = orig.head;
        tail = orig.tail;
        listSize = orig.listSize;
    }
}

Doubly::~Doubly() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
}

void Doubly::Push(int n){
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
    tail->next=NULL;
    listSize++;
}

void Doubly::Pop(){
    Node* temp = head;
    Node* temp2 = tail;
    if(head==NULL) return;
    else{
        if(temp->next==NULL){
            head=NULL;
            delete temp;
            listSize--;
        }
        else{
            head = head->next;
            while(temp2->prev!=NULL){
                temp2=temp2->prev;
            }
            temp2=head;
            temp2->prev=NULL;
            delete temp;
            listSize--;
        }
    }
}


void Doubly::Print(){
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

