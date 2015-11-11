/* 
 * File:   SimpleVector.h
 * Author: rcc
 *
 * Created on October 20, 2015, 5:06 PM
 */

#ifndef SIMPLEVECTOR_H
#define	SIMPLEVECTOR_H
#include "node.h"

class SimpleVector:public Node{
public:
    SimpleVector();
    SimpleVector(const SimpleVector& orig);
    virtual ~SimpleVector();
    void pushNode(int);
    void pullNode();
private:
    
};

#endif	/* SIMPLEVECTOR_H */

