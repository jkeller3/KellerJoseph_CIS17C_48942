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
    ~SimpleVector(){};
    void Print();
    void pushNode(int);
    void pullNode();
};

#endif	/* SIMPLEVECTOR_H */

