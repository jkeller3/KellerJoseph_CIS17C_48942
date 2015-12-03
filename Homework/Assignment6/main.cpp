/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on November 30, 2015, 5:31 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Node.h"
#include "Stack.h"

int main(int argc, char** argv) {

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
    
    return 0;
}

