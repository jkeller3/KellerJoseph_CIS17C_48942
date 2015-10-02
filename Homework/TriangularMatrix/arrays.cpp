#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "arrays.h"

template <class T>
Arrays<T>::Arrays(T col){
    cols = col;
}

template <class T>
Arrays<T>::~Arrays(void){
    delete []d1ary;
    for(int i=0;i<cols;i++){
        delete []d2ary[i];
    }
    delete []d2ary;
}

//Fills a 1-Dim array with the number of
//Columns per row
template <class T>
void Arrays<T>::filD1ary(void){
    d1ary=new T[cols];
    for(int i=0;i<cols;i++){
        //array[i]=rand()%10+1;
        d1ary[i]=i+1;
    }
}

//Fills a 1-Dim array with the number of
//Columns per row
template <class T>
void Arrays<T>::filD2ary(void){
    //Allocates Memory
    d2ary=new T*[cols];
    for(int i=0;i<cols;i++){
        d2ary[i]=new T[d1ary[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<cols;row++){
        for(int col=0;col<d1ary[row];col++){
            d2ary[row][col]=(float)(rand()%(9900-1000)) / 100.0;
        }
    }
}

template <class T>
void Arrays<T>::prntD1ary(void){
    std::cout<<std::endl;
    for(int i=0;i<cols;i++){
        std::cout<<d1ary[i]<<" ";
    }
    std::cout<<std::endl;
}

template <class T>
void Arrays<T>::prntD2ary(void){
    std::cout<<std::endl;
    //Print the allocated memory
    for(int row=0;row<cols;row++){
        for(int col=0;col<d1ary[row];col++){
            std::cout<<d2ary[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
