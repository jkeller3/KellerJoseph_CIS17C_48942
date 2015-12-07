/* 
 * File:   main.cpp
 * Author: Joseph Keller
 *
 * Created on December 6, 2015, 1:03 PM
 */

#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

void outputArray(int*,int);
void swap(int*,int,int);
void bubbleSort(int*,int);
void selectionSort(int*,int);
int* mergeSort(int*,int);
int* merge(int*,int*,int,int);
void quickSort(int*,int,int);
void heapSort(int*);

int main(int argc, char** argv) {
    srand(time(NULL));
    int size = 20;
    int* array = new int [size];
    for(int i=0; i<size; i++){
        array[i] = rand()%10+1;
    }
    outputArray(array,size);
    cout<<"With which method would you like this sorted?\n";
    cout<<"1 for Bubble Sort.\n";
    cout<<"2 for Selection Sort.\n";
    cout<<"3 for Merge Sort.\n";
    cout<<"4 for Quick Sort.\n";
    cout<<"5 for Heap Sort.\n";
    int input;
    cin>>input;
    if(input==1) bubbleSort(array,size);
    else if(input==2) selectionSort(array,size);
    else if(input==3) mergeSort(array,size);
    else if(input==4) quickSort(array, 0, size-1);
    else if(input==5) heapSort(array);
    else cout<<"Invalid input.\n";
    outputArray(array,size);
    delete array;
    return 0;
}

void outputArray(int* array, int size){
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void swap(int* array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void bubbleSort(int* array, int size){
    int i, j, temp, flag=1;
    for(i = 1; (i<=size)&&flag; i++){
        flag = 0;
        for (j=0; j<size-1; j++){
            if (array[j+1] < array[j]){ 
                swap(array,j,j+1);
                flag = 1;
            }
        }
    }
    return;
}

void selectionSort(int* array, int size){
    int i, j, first, temp;
    for (i=size-1; i>0; i--){
        first=0;
        for (j=1; j<=i; j++){
            if (array[j]>array[first])
            first=j;
        }
        swap(array, first, i);
    }
    return;
}

int* mergeSort(int* array,int size){
    if(size==1){
        return array;
    }
    int i=0, s1, s2;
    int* array1=new int[size/2];
    s1 = size/2;
    int* array2;
    if(size%2==1){
        array2=new int[size/2+1]; 
        s2=size/2+1;
    }
    else{ 
        array2=new int[size/2]; 
        s2=size/2;
    }
    while(i<size/2){
        array1[i]=array[i];
        i++;
    }
    int j=0;
    while(i<size){
        array2[j]=array[i];
        i++, j++;
    }
    array1=mergeSort(array1,s1);
    array2=mergeSort(array2,s2);
    return merge(array1,array2,s1,s2);
}

int* merge(int* a1, int* a2, int s1, int s2){
    int* a3 = new int [s1+s2-1];
    int i=0, j=0;
    while(a1[s1-1]!=0||a2[s2-1]!=0){
        if(a1[i]>a2[j]){
            a3[i+j]=a2[j];
            a2[j]=0;
            j++;
        }
        else{
            a3[i+j]=a1[i];
            a1[i]=0;
            i++;
        }
    }
    while(a1[s1-1]!=0){
        a3[i+j]=a1[i];
        a1[i]=0;
        i++;
    }
    while(a2[s2-1]!=0){
        a3[i+j]=a2[j];
        a2[j]=0;
        j++;
    }
    return a3;
}

void quickSort(int* array, int top, int bottom){
    int min = (top+bottom)/2;
    int i = top;
    int j = bottom;
    int pivot = array[min];
    while(top<j||i<bottom){
        while(array[i]<pivot)
        i++;
        while(array[j]>pivot)
        j--;
        if(i<=j){
            swap(array,i,j);
            i++;
            j--;
        }
        else{
            if(top<j)
                quickSort(array,top,j);
            if(i<bottom)
                quickSort(array,i,bottom);
            return;
        }
    }
}

void heapSort(int*){
    
}