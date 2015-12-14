/* 
 * File:   Vector.cpp
 * Author: joey
 * 
 * Created on December 11, 2015, 12:42 PM
 */
#include <stdio.h>
#include <vector>
#include <cstdlib>

#include "Vector.h"

Vector::Vector() {
}

Vector::Vector(const Vector& orig) {
}

Vector::~Vector() {
}

void Vector::obtainValues(){
    int input = 0;
    do{
        input=rand()%11;
        if(input!=0){
            numbers.push_back(input);
        }
    }while(input!=0&&numbers.size()!=0);
}

void Vector::outputArray(int num[], int size){
    for(int i=0;i<size;i++)
    {
        printf("%d ",num[i];
    }
    printf("\n");
}

void Vector::outputVector(vector<int> top, int num){
    printf("The top %d values are: ",num);
    for(int i=0; i<top.size(); i++){
        printf("%d ",top[i]);
    }
    printf("\n");
}

void Vector::sort(int num[], int size){
    int i, j, flag = 1;
    int temp;
    for(i = 1; (i <= size) && flag; i++){
        flag = 0;
        for (j=0; j < (size -1); j++)
        {
            if (num[j+1] < num[j])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
                flag = 1;
            }
        }
    }
    return;
}

vector<int> Vector::top(vector<int> x,int p){
    vector<int> v;
    int size = x.size();
    for(int i=0; i<p; i++){
        v.push_back(x[size-i-1]);
    }
    return v;
}

void Vector::mean(int num[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum+=num[i];
    }
    float mean = sum/static_cast<float>(size);
    printf("The mean is: %d.\n",mean);
}

void Vector::findMode(int num[], int size){
    int maxRepeat = findMaxRepeat(num, size); 
    if(maxRepeat==1){
        displayMode(0,0);
        return;
    }
    int modeCount = findModeCount(num, size, maxRepeat);
    int mode[modeCount-1];
    modeCount=0;
    int repeat=1;
    int number=num[0];
    for(int i=1; i<=size; i++){
        if(num[i] == number){
            repeat++;
        }
        else{
            if(repeat == maxRepeat){
                mode[modeCount]=number;
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    displayMode(mode, modeCount);    
}

int Vector::findMaxRepeat(int num[], int size){
    int number = num[0];
    int repeat = 1;
    int maxRepeat = 1;
    for (int i=1; i<=size; i++){
        if(num[i] == number){
            repeat++;
        }
        else{
            if(repeat>maxRepeat){
                maxRepeat=repeat;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return maxRepeat;
}

int Vector::findModeCount(int num[], int size, int maxRepeat){
    int modeCount = 0;
    int repeat = 1;
    int number = num[0];
    for (int i=1; i<=size; i++){
        if(num[i] == number){
            repeat++;
        }
        else{
            if(repeat == maxRepeat){
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return modeCount;
}

void Vector::displayMode(int array[], int size){
    if(size==0){
        printf("There is no mode.\n");
    } else if(size==1){
        printf("The mode is: %d.\n",array[0]);
    } else{
        printf("The modes are: ");
        outputArray(array, size);
    }
}