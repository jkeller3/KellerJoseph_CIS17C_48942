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
    };
    Node* head;
    int listSize;
public:
    Stack();
    Stack(const Stack& orig);
    virtual ~Stack();
    void Push(int);
    void Pop();
    void Print();
};

#endif	/* STACK_H */

