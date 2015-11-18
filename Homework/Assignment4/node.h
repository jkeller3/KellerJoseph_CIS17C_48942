/* 
 * File:   node.h
 * Author: rcc
 *
 * Created on October 20, 2015, 5:23 PM
 */

#ifndef NODE_H
#define	NODE_H

class Node{
    private:
        int x;
        Node *next;
    public:
        Node(){};
        void setX(int a){x=a;};
        void setNext(Node* aNext){next=aNext;};
        int getX(){return x;};
        Node* getNext(){return next;};
};

#endif	/* NODE_H */

