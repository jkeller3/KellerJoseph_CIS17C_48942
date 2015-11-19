/* 
 * File:   SimpleVector.cpp
 * Author: rcc
 * 
 * Created on October 20, 2015, 5:06 PM
 */
#include <iostream>
#include "SimpleVector.h"

void SimpleVector::Print(){
    Node *temp=head;
    do{
        std::cout<<temp->getX();
        std::cout<<" --> ";
        temp=temp->getNext();
    }while (temp!=NULL );
    std::cout<<"NULL\n";
}

void SimpleVector::prepend(int n){
    Node* temp = head;
    Node* push = new Node();
    push->setX(n);
    push->setNext(temp);
    head=push;
}

void SimpleVector::append(int n){
    Node* push = new Node();
    push->setX(n);
    push->setNext(NULL);
    
    Node *temp = head;
    if(temp!=NULL){
        while(temp->getNext()!=NULL){
            temp = temp->getNext();
        }
        temp->setNext(push);
    }
    else{
        head=push;
    }
}

void SimpleVector::pullNode(){
    Node *temp = head;
    if(temp==NULL){
        return;
    }
    if(temp->getNext()==NULL){
        delete temp;
        head=NULL;
    }
    else{
        Node *prev;
        do{
            if(temp->getNext()==NULL){
                prev->setNext(NULL);
            }
            prev=temp;
            temp=temp->getNext();
        }while(temp!=NULL);
        delete temp;
    }
}

void SimpleVector::first(){
    Node *temp = head;
    std::cout<<"First: "<<temp->getX()<<std::endl;
}

void SimpleVector::last(){
    Node *temp = head;
    do{
        temp=temp->getNext();
    }while(temp->getNext()!=NULL);
    std::cout<<"Last: "<<temp->getX()<<std::endl;
}