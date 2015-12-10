/* 
 * File:   LinkedList.h
 * Author: rcc
 *
 * Created on December 8, 2015, 4:25 PM
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

class LinkedList {
private:
    struct Node{
        int x;
        Node* next;
    };
    Node* head;
    Node* mode;
    int listSize;
public:
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    int* TopNums(int&);
    void Push(int);
    void findMode();
    int findMaxRepeat();
    int findModeCount();
    void displayMode();
    void Print();
};

#endif	/* LINKEDLIST_H */

