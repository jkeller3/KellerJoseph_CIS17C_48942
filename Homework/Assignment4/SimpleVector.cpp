/* 
 * File:   SimpleVector.cpp
 * Author: rcc
 * 
 * Created on October 20, 2015, 5:06 PM
 */

#include "SimpleVector.h"

SimpleVector::SimpleVector() {
}

SimpleVector::SimpleVector(const SimpleVector& orig) {
}

SimpleVector::~SimpleVector() {
}

void SimpleVector::pushNode(int n){
    Node* push = new Node;
    tail->next=push;
    push->next=0;
    push->x=n;
}

void SimpleVector::pullNode(){
    mid->next=0;
}