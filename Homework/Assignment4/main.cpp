/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Assignment: 4
 * Created on October 20, 2015, 5:05 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "SimpleVector.h"
#include "Node.h"

void array();
void linkedlist();
void output(int, int*);

int main(int argc, char** argv) {
    array();
    linkedlist();
    return 0;
}

void array(){
    int* array = new int[10];
    array[0]=3;
    array[1]=5;
    array[2]=10;
    int size=3;
    cout<<"Array implementation: \n";
    output(size,array);
    cout<<"Enter 1 to push. 2 to pull. 0 to exit.\n";
    int input;
    do{
        cin>>input;
        if(input==1){
            array[size]=5;
            size++;
            output(size,array);
        }
        if(input==2){
            array[size-1]=0;
            size--;
            output(size,array);
        }
    }while(input!=0);
}

void linkedlist(){
    SimpleVector list;
    list.pushNode(3);
    list.pushNode(5);
    list.pushNode(10);
    cout<<"Linked List implementation: \n";
    list.Print();
    cout<<"Enter 1 to push. 2 to pull. 0 to exit.\n";
    int input;
    do{
        cin>>input;
        if(input==1){
            list.pushNode(5);
            list.Print();
        }
        if(input==2){
            list.pullNode();
            list.Print();
        }
    }while(input!=0);
}

void output(int size, int*array){
    for(int i=0; i<size; i++){
        cout<<array[i]<<" --> ";
    }
    cout<<"NULL\n";
}