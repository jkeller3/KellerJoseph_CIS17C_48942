/* 
 * File:   Sorting.h
 * Author: rcc
 *
 * Created on December 16, 2015, 5:57 PM
 */

#ifndef SORTING_H
#define	SORTING_H

class Sorting {
private:
    unsigned short int* list;
    int top;
    int size;
public:
    Sorting();
    Sorting(int,int);
    Sorting(const Sorting& orig);
    virtual ~Sorting();
    void Menu();
    void FillList();
    void Swap(int,int);
    void BubbleSort();
    void SelectionSort();
    void MergeSort();
    unsigned short int* MergeSort(unsigned short int*,int);
    unsigned short int* Merge(unsigned short int*,unsigned short int*,int,int);
    void QuickSort(int,int);
    void HeapSort();
    void Print();
    void PrintTop();
};

#endif	/* SORTING_H */

