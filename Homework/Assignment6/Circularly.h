/* 
 * File:   Circularly.h
 * Author: rcc
 *
 * Created on December 2, 2015, 7:46 PM
 */

#ifndef CIRCULARLY_H
#define	CIRCULARLY_H
#include <stddef.h>

class Circularly {
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
    Circularly();
    Circularly(const Circularly& orig);
    virtual ~Circularly();
    void Push(int);
    void Pop();
    void Print();
};

#endif	/* CIRCULARLY_H */

