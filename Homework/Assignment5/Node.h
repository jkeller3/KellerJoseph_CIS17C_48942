/* 
 * File:   Node.h
 * Author: rcc
 *
 * Created on October 20, 2015, 5:23 PM
 */

#ifndef NODE_H
#define	NODE_H

template<class T>
class Node{
        T x;
        Node<T> *next;
    public:
        Node(){};
        ~Node(){};
        void setX(T a){x=a;};
        void setNext(Node<T> *aNext){next=aNext;};
        T getX(){return x;};
        Node<T>* getNext(){return next;};
};

#endif	/* NODE_H */

