/* 
 * File:   Stack.cpp
 * Author: rcc
 * 
 * Created on December 2, 2015, 3:14 PM
 */

#include "Stack.h"
#include <iostream>

Stack::Stack(){
    head = NULL;
    listSize=0;
}

Stack::Stack(const Stack& orig) {
    if(this != &orig){
        head = orig.head;
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
    push->next=head;
    head=push;
    listSize++;
}

void Stack::Pop(){
    Node* temp = head;
    if(head==NULL) return;
    else{
        if(temp->next==NULL){
        head=NULL;
        delete temp;
        listSize--;
    }
    else{
        head = head->next;
        delete temp;
        listSize--;
    }
    }
    
}

void Stack::Print(){
    Node* temp=head;
    if(temp==NULL){
        std::cout<<"List is empty.\n";
    }
    else if(temp->next==NULL){
        std::cout<<temp->x;
        std::cout<<" --> ";
        std::cout<<"NULL\n";
    }
    else{
        while (temp!=NULL){
            std::cout<<temp->x;
            std::cout<<" --> ";
            temp=temp->next;
        }
        std::cout<<"NULL\n";
    }
}

