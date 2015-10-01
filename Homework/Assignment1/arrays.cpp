#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "arrays.h"

Arrays::Arrays(int col){
    cols = col;
    filD1ary();
}

Arrays::~Arrays(void){
    delete []d1ary;
    for(int i=0;i<cols;i++){
        delete []d2ary[i];
    }
    delete []d2ary;
}

//Fills a 1-Dim array with the number of
//Columns per row
void Arrays::filD1ary(void){
    int *array=new int[cols];
    for(int i=0;i<cols;i++){
        //array[i]=rand()%10+1;
        array[i]=i+1;
    }
    filD2ary();
}

//Fills a 1-Dim array with the number of
//Columns per row
void Arrays::filD2ary(void){
    //Allocates Memory
    int **array=new int*[cols];
    for(int i=0;i<cols;i++){
        array[i]=new int[d1ary[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<cols;row++){
        for(int col=0;col<d1ary[row];col++){
            array[row][col]=rand()%90+10;
        }
    }
}

void Arrays::prntD1ary(void){
    std::cout<<std::endl;
    for(int i=0;i<cols;i++){
        std::cout<<d1ary[i]<<" ";
    }
    std::cout<<std::endl;
}

void Arrays::prntD2ary(void){
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
