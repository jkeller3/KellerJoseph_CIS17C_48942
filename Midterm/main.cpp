#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

#include "LinkedList.h"
#include "SelfOrganizingList.h"
#include "Vector.h"

void menu();
int getN();
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void def(int);



int main(int argc, char** argv) {
    int inN;
    do{
        menu();
        inN=getN();
        switch(inN){
            case 1:
                problem1();
                break;
            case 2:
                problem2();
                break;
            case 3:
                problem3();
                break;
            case 4:
                problem4();
                break;
            case 5:
                problem5();
                break;
            case 6:
                problem6();
                break;
            case 7:
                problem7();
                break;
            default:
                def(inN);
        }    
    }while(inN>=1 && inN<=7);
    
    return 0;
}

void menu(){
    cout<<"Enter 1 for Problem 1\n";
    cout<<"Enter 2 for Problem 2\n";
    cout<<"Enter 3 for Problem 3\n";
    cout<<"Enter 4 for Problem 4\n";
    cout<<"Enter 5 for Problem 5\n";
    cout<<"Enter 6 for Problem 6\n";
    cout<<"Enter 7 for Problem 7\n";
    cout<<"Enter any other number to exit\n";
}

int getN(){
    int inN;
    cin>>inN;
    return inN;
}

void problem1(){
    srand(time(NULL));
    Vector nums;
    nums.obtainValues();
    while(nums.size()==0){
        nums.obtainValues();
        size=numbers.size();
    }
    int *array = numbers.data();
    outputArray(array,size);
    sort(array,size);
    outputArray(array,size);
    vector<int> topNums;
    int num;
    while(topNums.size()==0){
        cout<<"How many of the top elements would you like?\n";
        cin>>num;
        if(num<=numbers.size()){
            topNums=top(numbers,num);
        }
    }
    outputVector(topNums,num);
    mean(array,size);
    findMode(array,size);
    array = new int;
    delete array;
    array = NULL;
}

void problem2(){
    
}

void problem3(){
    
}

void problem4(){
    LinkedList list; 
    int num=1;
    cout<<"Enter as many numbers as you'd like. Enter 0 to stop.\n";
    while(num!=0){
        num=getN();
        if(num!=0) list.Push(num);
    }
    cout<<"How many of the top numbers would you like returned back?\n";
    num=getN();
    int* top=new int [num];
    top=list.TopNums(num);
    for(int i=0; i<num; i++){
        cout<<top[i]<<" ";
    }
    cout<<"\n";
}

void problem5(){
    
}

void problem6(){
    
}

void problem7(){
    LinkedList list;
    list.Push(1);
    list.Push(3);
    list.Push(5);
    list.Push(7);
    list.Push(9);
    list.Push(7);
    list.Print();
    int num=1;
    do{
        cout<<"Which number would you like to move to the front of the list?";
        cout<<" Enter 0 to exit.\n";
        num = getN();
        list.NumExist(num);
    }while(num!=0);
}

void def(int inN){
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
}