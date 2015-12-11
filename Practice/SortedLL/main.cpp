/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 9, 2015, 6:42 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "LinkedList.h"

int getN();

int main(int argc, char** argv) {
    LinkedList list; 
    int num=1;
    cout<<"Enter as many numbers as you'd like. Enter 0 to stop.\n";
    while(num!=0){
        num=getN();
        if(num!=0) list.Push(num);
    }
    list.Print();
    cout<<"How many of the top numbers would you like returned back?\n";
    num=getN();
    int* top=new int [num];
    top=list.TopNums(num);
    for(int i=0; i<num; i++){
        cout<<top[i]<<" ";
    }
    cout<<"\n";
    list.FindMode();
    delete top;
    
    return 0;
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}