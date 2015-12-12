#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

#include "LinkedList.h"
#include "SelfOrganizingList.h"

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
vector<int> obtainValues();
void outputArray(int num[], int size); 
void outputVector(vector<int>,int);
void sort(int num[], int size); 
vector<int> top(vector<int>,int);
void mean(int num[], int size);
void findMode(int num[], int size);
int findMaxRepeat(int num[], int size);
int findModeCount(int num[], int size, int maxRepeat);
void displayMode(int num[], int size);


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
    vector<int>numbers = obtainValues();
    int size = numbers.size();
    while(size==0){
        numbers=obtainValues();
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

void def(int inN)
{
    cout<<"You entered "<<inN<<" to exit the program"<<endl;
}

vector<int> obtainValues(){
    vector<int>numbers;
    int input = 0;
    do{
        input=rand()%11;
        if(input!=0){
            numbers.push_back(input);
        }    
    }while(input!=0);
    return numbers;
}

void outputArray(int num[], int size){
    for(int i=0;i<size;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

void outputVector(vector<int> top, int num){
    cout<<"The top "<<num<<" values are: ";
    for(int i=0; i<top.size(); i++){
        cout<<top[i]<<" ";
    }
    cout<<endl;
}

void sort(int num[], int size){
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

vector<int> top(vector<int> x,int p){
    vector<int> v;
    int size = x.size();
    for(int i=0; i<p; i++){
        v.push_back(x[size-i-1]);
    }
    return v;
}

void mean(int num[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum+=num[i];
    }
    float mean = sum/static_cast<float>(size);
    cout<<"The mean is: "<<mean<<".\n";
}

void findMode(int num[], int size){
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

int findMaxRepeat(int num[], int size){
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

int findModeCount(int num[], int size, int maxRepeat){
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

void displayMode(int array[], int size){
    if(size==0){
        cout<<"There is no mode.\n";
    }
    else if(size==1){
        cout<<"The mode is: "<<array[0]<<".\n";
    }
    else{
        cout<<"The modes are: ";
        outputArray(array, size);
    }
}