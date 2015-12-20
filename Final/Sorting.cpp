/* 
 * File:   Sorting.cpp
 * Author: rcc
 * 
 * Created on December 16, 2015, 5:57 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Sorting.h"
#include "BinaryTrees.h"
#include "AdjList.h"

Sorting::Sorting() {
    size = 100000;
    list = new unsigned short int[size];
    top = 10;
}

Sorting::Sorting(int size, int p){
    this->size = size;
    list = new unsigned short int[size];
    top = p;
}

Sorting::Sorting(const Sorting& orig) {
    list = orig.list;
    top = orig.top;
}

Sorting::~Sorting() {
    delete list;
}

void Sorting::Menu(){
    printf("1 for Bubble Sort.\n");
    printf("2 for Selection Sort.\n");
    printf("3 for Merge Sort.\n");
    printf("4 for Quick Sort.\n");
    printf("5 for Heap Sort.\n");
    printf("Type 0 to exit\n");
}

void Sorting::FillList(){
    for(int i=0; i<size; i++)
        list[i] = rand() % 65535;
}

void Sorting::Swap(int i, int j){
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void Sorting::BubbleSort(){
    int i, j, flag=1;
    for(i = 1; (i<=size)&&flag; i++){
        flag = 0;
        for (j=0; j<size-1; j++){
            if (list[j+1] < list[j]){ 
                Swap(j,j+1);
                flag = 1;
            }
        }
    }
}

void Sorting::SelectionSort(){
    int i, j, first;
    for (i=size-1; i>0; i--){
        first=0;
        for (j=1; j<=i; j++){
            if (list[j]>list[first])
            first=j;
        }
        Swap(first, i);
    }
}

void Sorting::MergeSort(){
    if(size==1){
        return;
    }
    int i=0;
    unsigned short int* left=new unsigned short int[size/2];
    int leftSize = size/2;
    unsigned short int* right=new unsigned short int [size-leftSize];
    int rightSize = size-leftSize;
    while(i<size/2){
        left[i]=list[i];
        i++;
    }
    int j=0;
    while(i<size){
        right[j]=list[i];
        i++, j++;
    }
    left=MergeSort(left,leftSize);
    right=MergeSort(right,rightSize);
    list=Merge(left,right,leftSize,rightSize);
}

unsigned short int* Sorting::MergeSort(unsigned short int* array, int s){
    if(s==1){
        return array;
    }
    int i=0;
    unsigned short int* left=new unsigned short int[s/2];
    int leftSize = s/2;
    unsigned short int* right=new unsigned short int[s-leftSize];
    int rightSize = s-leftSize;
    while(i<s/2){
        left[i]=array[i];
        i++;
    }
    int j=0;
    while(i<s){
        right[j]=array[i];
        i++, j++;
    }
    left=MergeSort(left,leftSize);
    right=MergeSort(right,rightSize);
    return Merge(left,right,leftSize,rightSize);
}

unsigned short int* Sorting::Merge(unsigned short int* left,
        unsigned short int* right, int leftSize, int rightSize){
    unsigned short int* a3 = new unsigned short int [leftSize+rightSize];
    int i=0, j=0;
    while(i < leftSize && j < rightSize){
        if(left[i]>right[j]){
            a3[i+j]=right[j];
            j++;
        }
        else{
            a3[i+j]=left[i];
            i++;
        }
    }
    while(i < leftSize) {
        a3[i+j]=left[i];
        i++;
    }
    while(j < rightSize) {
        a3[i+j]=right[j];
        j++;
    }
    delete left, right;
    return a3;
}

void Sorting::HeapSort(unsigned short int* a, int n){
    int i, temp;
    for (i = n; i >= 2; i--){
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        Heapify(a, 1, i - 1);
    }
}

void Sorting::Build(){
    unsigned short int* a = list;
    int n = size;
    for(int i = n/2; i >= 1; i--){
        Heapify(a, i, n);
    }
    list=a;
}

void Sorting::Heapify(unsigned short int* a, int i, int n){
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n){
        if(j < n && a[j+1] < a[j]){
            j++;
        }
        if(temp < a[j]){
            break;
        }
        else if(temp >= a[j]){
            a[j/2] = a[j];
            j=2*j;
        }
    }
    a[j/2] = temp;
    printf("%d\n",j);
    return;
}

void Sorting::QuickSort(int top, int bottom){
    int min = (top+bottom)/2;
    int i = top;
    int j = bottom;
    int pivot = list[min];
    while(top<j||i<bottom){
        while(list[i]<pivot)
        i++;
        while(list[j]>pivot)
        j--;
        if(i<=j){
            Swap(i,j);
            i++;
            j--;
        } else{
            if(top<j)
                QuickSort(top,j);
            if(i<bottom)
                QuickSort(i,bottom);
            return;
        }
    }
}

void Sorting::Print(){
    for(int i=0; i<size; i++)
        printf("%d ",list[i]);
}

void Sorting::PrintTop(){
    printf("The top %d numbers are: ",top);
    for(int i=0; i<top; i++)
        printf("%d ",list[i]);
    printf("\n");
}