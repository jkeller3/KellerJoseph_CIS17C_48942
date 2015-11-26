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
    if(!head){
        return;
    }
    Node* temp = head;
    Node* prev = 0;
 
    while (temp!=NULL){
        if (temp->getX()==n){
            if (prev != NULL){
                prev->setNext(temp->getNext());
                temp = temp->getNext();
                // Keep prev as is
            }
            else{
                // prev is null
                Node * next = temp->getNext();
                temp->setNext(NULL);
                temp = next;
                head = next;
            }
        } 
        else{
            // not n
            prev = temp;
            temp = temp->getNext();
        }
    }
}

void SimpleVector::Traverse(){
    if(!head){
        std::cout<<"The list is empty.\n";
    }
    Node *temp = head;
    bool insert = false;
    int counter = 0;
    while(insert==false){
        this->Print();
        for(int i=0; i<counter; i++){
            std::cout<<"      ";
        }
        std::cout<<"^\n";
        std::cout<<"Insert here? Enter 1 for yes. 0 for no.\n";
        int input;
        std::cin>>input;
        if(input==1){
            input=0;
            std::cout<<"Enter 1 for before, or 2 for after.\n";
            std::cin>>input;
            if(input==1){
                this->InsBefore();
            }
            if(input==2){
                this->InsAfter();
            }
        }
        counter++;
    }
    
}

void SimpleVector::InsAfter(){
    
}

void SimpleVector::InsBefore(){
    
}