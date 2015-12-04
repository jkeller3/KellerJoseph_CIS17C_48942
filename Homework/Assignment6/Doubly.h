/* 
 * File:   Doubly.h
 * Author: rcc
 *
 * Created on December 2, 2015, 6:35 PM
 */

#ifndef DOUBLY_H
#define	DOUBLY_H
#include <stddef.h>

class Doubly {
private:
    struct Node{
        int x;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int listSize;
public:
    Doubly();
    Doubly(const Doubly& orig);
    virtual ~Doubly();
    void Push(int);
    void Pop();
    void Print();
};

#endif	/* STACK_H */
