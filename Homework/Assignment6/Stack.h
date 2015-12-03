/* 
 * File:   Stack.h
 * Author: rcc
 *
 * Created on December 2, 2015, 3:14 PM
 */

#ifndef STACK_H
#define	STACK_H
#include <stddef.h>
class Stack {
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
    Stack() {head->prev=NULL; tail->prev=NULL; listSize=0;};
    Stack(const Stack& orig);
    virtual ~Stack();
    void Push(int);
    void Pop();
    void Empty();
    void Print();
};

#endif	/* STACK_H */

