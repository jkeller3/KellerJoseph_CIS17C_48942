/* 
 * File:   SimpleVector.cpp
 * Author: rcc
 * 
 * Created on October 20, 2015, 5:06 PM
 */
#include <iostream>
#include "SimpleVector.h"

SimpleVector::SimpleVector(const SimpleVector& orig){
    if(this != &orig){
        head = orig.head;
    }
}

void SimpleVector::Print(){
    Node *temp=head;
    do{
        std::cout<<temp->getX();
        std::cout<<" --> ";
        temp=temp->getNext();
    }while (temp!=NULL );
    std::cout<<"NULL\n";
}

void SimpleVector::Prepend(int n){
    Node* temp = head;
    Node* push = new Node();
    push->setX(n);
    push->setNext(temp);
    head=push;
}

void SimpleVector::Append(int n){
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

void SimpleVector::PullNode(){
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

void SimpleVector::First(){
    Node *temp = head;
    std::cout<<"First: "<<temp->getX()<<std::endl;
}

void SimpleVector::Last(){
    Node *temp = head;
    do{
        temp=temp->getNext();
    }while(temp->getNext()!=NULL);
    std::cout<<"Last: "<<temp->getX()<<std::endl;
}

void SimpleVector::Extract(int n){
    Node *temp = head;
    if(temp==NULL){ //returns if list is empty
        return;
    }
    else{
        do{
            if(temp->getX()==n){ //if that spot is equal to the number
                temp->setNext(temp->getNext()); //removes it and sets
            }                           //to the next spot in the list
            else{
                temp=temp->getNext(); //if the spot isn't the number, 
            }                         //moves to check next spot.
        }while(temp!=NULL);
    }
}