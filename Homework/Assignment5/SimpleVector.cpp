/* 
 * File:   SimpleVector.cpp
 * Author: rcc
 * 
 * Created on October 20, 2015, 5:06 PM
 */
#include <iostream>
#include "SimpleVector.h"

//template<class T>
//SimpleVector<T>::SimpleVector(const SimpleVector& orig){
//    if(this != &orig){
//        head = orig.head;
//        listSize = orig.listSize;
//    }
//}
//
//template<class T>
//SimpleVector<T>::~SimpleVector(){
//    
//};
//
//template<class T>
//void SimpleVector<T>::Print(){
//    Node<T> *temp=head;
//    do{
//        std::cout<<temp->getX();
//        std::cout<<" --> ";
//        temp=temp->getNext();
//    }while (temp!=NULL );
//    std::cout<<"NULL\n";
//}
//
//template<class T>
//void SimpleVector<T>::Prepend(T n){
//    Node<T>* temp = head;
//    Node<T>* push = new Node<T>();
//    push->setX(n);
//    push->setNext(temp);
//    head=push;
//    listSize++;
//}
//
//template<class T>
//void SimpleVector<T>::Append(T n){
//    Node<T>* push = new Node<T>();
//    push->setX(n);
//    push->setNext(NULL);
//    
//    Node<T> *temp = head;
//    if(temp!=NULL){
//        while(temp->getNext()!=NULL){
//            temp = temp->getNext();
//        }
//        temp->setNext(push);
//    }
//    else{
//        head=push;
//    }
//    listSize++;
//}
//
//template<class T>
//void SimpleVector<T>::PullNode(){
//    Node<T> *temp = head;
//    if(temp==NULL){
//        return;
//    }
//    if(temp->getNext()==NULL){
//        delete temp;
//        head=NULL;
//    }
//    else{
//        Node<T> *prev;
//        do{
//            if(temp->getNext()==NULL){
//                prev->setNext(NULL);
//            }
//            prev=temp;
//            temp=temp->getNext();
//        }while(temp!=NULL);
//        delete temp;
//        listSize++;
//    }
//}
//
//template<class T>
//void SimpleVector<T>::First(){
//    Node<T> *temp = head;
//    std::cout<<"First: "<<temp->getX()<<std::endl;
//}
//
//template<class T>
//void SimpleVector<T>::Last(){
//    Node<T> *temp = head;
//    do{
//        temp=temp->getNext();
//    }while(temp->getNext()!=NULL);
//    std::cout<<"Last: "<<temp->getX()<<std::endl;
//}
//
//template<class T>
//void SimpleVector<T>::Extract(T n){
//    if(!head){
//        return;
//    }
//    Node<T>* temp = head;
//    Node<T>* prev = 0;
// 
//    while (temp!=NULL){
//        if (temp->getX()==n){
//            if (prev != NULL){
//                prev->setNext(temp->getNext());
//                temp = temp->getNext();
//                // Keep prev as is
//            }
//            else{
//                // prev is null
//                Node<T>* next = temp->getNext();
//                temp->setNext(NULL);
//                temp = next;
//                head = next;
//                listSize--;
//            }
//        } 
//        else{
//            // not n
//            prev = temp;
//            temp = temp->getNext();
//        }
//    }
//}
//
//template<class T>
//void SimpleVector<T>::Traverse(){
//    if(!head){
//        std::cout<<"The list is empty.\n";
//    }
//    Node<T> *temp = head;
//    bool insert = false;
//    int counter = 0;
//    while(insert==false && listSize > counter){
//        this->Print();
//        for(int i=0; i<counter; i++){
//            std::cout<<"      ";
//        }
//        std::cout<<"^\n";
//        std::cout<<"Insert here? Enter 1 for yes. 0 for no.\n";
//        int input;
//        std::cin>>input;
//        if(input==1){
//            input=0;
//            std::cout<<"Enter 1 for before, or 2 for after.\n";
//            std::cin>>input;
//            if(input==1){
//                this->InsBefore(counter);
//                insert=true;
//            }
//            if(input==2){
//                this->InsAfter(counter);
//                insert=true;
//            }
//        }
//        counter++;
//    }
//    if(listSize == counter){
//        std::cout<<"Reached end of list, try again.\n";
//    }
//}
//
//template<class T>
//void SimpleVector<T>::InsAfter(int counter){
//    Node<T>* temp = head;
//    Node<T>* prev = temp;
//    prev=prev->getNext();
//    Node<T>* ins = new Node<T>();
//    ins->setX(9);
//    for(int i=1; i<counter; i++){
//        temp=temp->getNext();
//        prev=prev->getNext();
//    }
//    temp->setNext(ins);
//    ins->setNext(prev);
//    listSize++;
//}
//
//template<class T>
//void SimpleVector<T>::InsBefore(int counter){
//    Node<T>* temp=head;
//    Node<T>* ins = new Node<T>();
//    ins->setX(7);
//    if(counter==0){
//        ins->setNext(temp);
//        head=ins;
//    }
//    else{
//        Node<T>* prev = temp;
//        prev=prev->getNext();
//        for(int i=1; i<counter-1; i++){
//            temp=temp->getNext();
//            prev=prev->getNext();
//        }
//        temp->setNext(ins);
//        ins->setNext(prev);
//    }
//    listSize++;
//}