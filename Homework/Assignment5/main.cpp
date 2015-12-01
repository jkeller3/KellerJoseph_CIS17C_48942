/* 
 * File:   main.cpp
 * Author: Joseph Keller
 * Assignment: 5
 * Created on November 18, 2015, 6:21 PM
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
    //array();
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
    int input;
    do{
        cout<<"Enter 1 to push. 2 to pull. 0 to exit.\n";
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
    SimpleVector<int> list;
    list.Append(3);
    list.Append(5);
    list.Append(10);
    cout<<"Linked List implementation: \n";
    list.Print();
    int input;
    do{
        cout<<"Enter 1 to prepend\n";
        cout<<"Enter 2 to append.\n";
        cout<<"Enter 3 to pull.\n";
        cout<<"Enter 4 for first.\n";
        cout<<"Enter 5 for last.\n";
        cout<<"Enter 6 for copy.\n";
        cout<<"Enter 7 for extract.\n";
        cout<<"Enter 8 for insert.\n";
        cout<<"Enter 0 to exit.\n";
        cin>>input;
        if(input==1){
            list.Prepend(6);
            list.Print();
        }
        if(input==2){
            list.Append(5);
            list.Print();
        }
        if(input==3){
            list.PullNode();
            list.Print();
        }
        if(input==4){
            list.First();
        }
        if(input==5){
            list.Last();
        }
        if(input==6){
            SimpleVector<int> copy(list);
            copy.Print();
        }
        if(input==7){
            cout<<"What number would you like to extract?\n";
            int n;
            cin>>n;
            list.Extract(n);
            list.Print();
        }
        if(input==8){
            list.Traverse();
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