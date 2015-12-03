/* 
 * File:   Stack.cpp
 * Author: rcc
 * 
 * Created on December 2, 2015, 3:14 PM
 */

#include "Stack.h"
#include <iostream>

Stack::Stack(const Stack& orig) {
    if(this != &orig){
        head = orig.head;
        tail = orig.tail;
        listSize = orig.listSize;
    }
}

Stack::~Stack() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
}

void Stack::Push(int n){
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

void Stack::Pop(){
    if(head->next==NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    listSize--;
}

void Stack::Print(){
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
        temp=temp2->next;
    }
    std::cout<<"NULL\n";
}

