/* 
 * File:   LinkedList.cpp
 * Author: rcc
 * 
 * Created on December 8, 2015, 4:25 PM
 */
#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& orig) {
    this->head=orig.head;
    this->listSize=orig.listSize;
}

LinkedList::~LinkedList() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
}

int* LinkedList::TopNums(int p){
    int* top = new int [p];
    Node* temp = head;
    for(int i=0; i<p; i++){
        top[i]=temp->x;
        temp=temp->next;
    }
    return top;
}

void LinkedList::Push(int n){
    Node* push = new Node();
    push->x=n;
    push->next=NULL;
    Node *temp = head;
    if(head->next==NULL){
        if(push->x>temp->x){
            head=push;
            push->next=temp;
        }
        else{
            temp->next=push;
        }
    }
    else if(head!=NULL){
        Node *prev = head->next;
        while(push->x>temp->x&&prev!=NULL){
            temp = temp->next;
            prev = prev->next;
        }
        temp->next=push;
        push->next=prev;
    }
    else{
        head=push;
    }
    listSize++;
}

void LinkedList::Print(){
    Node *temp=head;
    do{
        std::cout<<temp->x;
        std::cout<<" --> ";
        temp=temp->next;
    }while (temp!=NULL );
    std::cout<<"NULL\n";
}

