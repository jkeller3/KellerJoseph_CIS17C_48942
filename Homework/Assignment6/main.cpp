/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on November 30, 2015, 5:31 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Doubly.h"
#include "Stack.h"
#include "Circularly.h"

void stackLL();
void doublyLL();
void circularlyLL();
void priorityLL();
void sortedLL();

int main(int argc, char** argv) {
    int input;
    do{
        cout<<"Enter 1 for a stack linked list.\n";
        cout<<"Enter 2 for a doubly linked list.\n";
        cout<<"Enter 3 for a circularly linked list.\n";
        cout<<"Enter 4 for a priority linked list.\n";
        cout<<"Enter 5 for a sorted linked list.\n";
        cout<<"Enter 0 to exit.\n";
        cin>>input;
        if(input==1){
            stackLL();
        }
        if(input==2){
            doublyLL();
        }
        if(input==3){
            circularlyLL();
        }

    }while(input!=0);
    return 0;
}

void stackLL(){
    Stack list;
    list.Push(3);
    list.Push(5);
    list.Push(10);
    list.Print();
    int input=1;
    while(input!=0){
        cout<<"Enter 1 for push. 2 for pop. Or 0 to exit.\n";
        cin>>input;
        if(input==1){
            int push;
            cout<<"What number would you like to push?\n";
            cin>>push;
            list.Push(push);
            list.Print();
        }
        else if(input==2){
            list.Pop();
            list.Print();
        }
    }
}

void doublyLL(){
    Doubly list;
    list.Push(4);
    list.Push(6);
    list.Push(2);
    list.Push(10);
    list.Print();
    int input=1;
    while(input!=0){
        cout<<"Enter 1 for push. 2 for pop. Or 0 to exit.\n";
        cin>>input;
        if(input==1){
            int push;
            cout<<"What number would you like to push?\n";
            cin>>push;
            list.Push(push);
            list.Print();
        }
        else if(input==2){
            list.Pop();
            list.Print();
        }
    }
}

void circularlyLL(){
    Circularly list;
    list.Push(1);
    list.Push(5);
    list.Push(3);
    list.Print();
    int input=1;
    while(input!=0){
        cout<<"Enter 1 for push. 2 for pop. Or 0 to exit.\n";
        cin>>input;
        if(input==1){
            int push;
            cout<<"What number would you like to push?\n";
            cin>>push;
            list.Push(push);
            list.Print();
        }
        else if(input==2){
            list.Pop();
            list.Print();
        }
    }
}

void priorityLL(){
    
}

void sortedLL(){
    
}