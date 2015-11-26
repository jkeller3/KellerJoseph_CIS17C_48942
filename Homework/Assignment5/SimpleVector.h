/* 
 * File:   SimpleVector.h
 * Author: rcc
 *
 * Created on October 20, 2015, 5:06 PM
 */

#ifndef SIMPLEVECTOR_H
#define	SIMPLEVECTOR_H
#include "node.h"

class SimpleVector{
    Node *head;
public:
    SimpleVector() {head=NULL;};
    SimpleVector(const SimpleVector&);
    ~SimpleVector(){};
    void Print();
    void Prepend(int);
    void Append(int);
    void PullNode();
    void First();
    void Last();
    void Extract(int);
    void Traverse();
    void InsAfter();
    void InsBefore();
};

#endif	/* SIMPLEVECTOR_H */

