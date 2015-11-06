
#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

vector<int> obtainValues();
void outputArray(int num[], int size); 
void sort(int num[], int size); 
vector<int> *top(vector<int>,int);
void mean(int num[], int size);
void median(int num[], int size);
void findMode(int num[], int size);
int findMaxRepeat(int num[], int size);
int findModeCount(int num[], int size, int maxRepeat);
void displayMode(int num[], int size);


int main(int argc, char** argv) {
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
    while(topNums.size()==NULL){
        int num;
        cout<<"How many of the top elements would you like?\n";
        cin>>num;
        if(num<=numbers.size()){
            topNums=top(numbers,num);
        }
    }
    int tSize = topNums.size();
    outputArray(topNums,tSize);
    mean(array,size);
    median(array,size);
    findMode(array,size);
    array = new int;
    delete array;
    array = NULL;

    return 0;
}

vector<int> obtainValues()
{
    vector<int>numbers;
    int input = 0;
    do{
        input=rand()%11;
        if(input!=0)
        {
            numbers.push_back(input);
        }    
    }while(input!=0);
    return numbers;
}

void outputArray(int num[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}

void sort(int num[], int size)
{
    int i, j, flag = 1;
    int temp;
    for(i = 1; (i <= size) && flag; i++)
    {
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

vector<int> *top(vector<int> x,int p){
    vector<int> v;
    int size = x.size();
    for(int i=0; i<p; i++){
        v=x[size-i];
    }
    return v;
}

void mean(int num[], int size)
{
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum+=num[i];
    }
    float mean = sum/static_cast<float>(size);
    cout<<"The mean is: "<<mean<<".\n";
}

void median(int num[], int size)
{
    float median=0;
    if(size%2==1)
    {
        median=num[size/2];
        cout<<"The median is: "<<median<<".\n";
    }
    if(size%2==0)
    {
        median=(num[size/2]+num[(size/2)-1])/static_cast<float>(2);
        cout<<"The median is: "<<median<<".\n";
    }
}

void findMode(int num[], int size)
{
    int maxRepeat = findMaxRepeat(num, size); 
    if(maxRepeat==1)
    {
        displayMode(0,0);
        return;
    }
    int modeCount = findModeCount(num, size, maxRepeat);
    int mode[modeCount-1];
    modeCount=0;
    int repeat=1;
    int number=num[0];
    for(int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat == maxRepeat)
            {
                mode[modeCount]=number;
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    displayMode(mode, modeCount);    
}

int findMaxRepeat(int num[], int size)
{
    int number = num[0];
    int repeat = 1;
    int maxRepeat = 1;
    for (int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat>maxRepeat)
            {
                maxRepeat=repeat;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return maxRepeat;
}

int findModeCount(int num[], int size, int maxRepeat)
{
    int modeCount = 0;
    int repeat = 1;
    int number = num[0];
    for (int i=1; i<=size; i++)
    {
        if(num[i] == number)
        {
            repeat++;
        }
        else
        {
            if(repeat == maxRepeat)
            {
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return modeCount;
}

void displayMode(int array[], int size)
{
    if(size==0)
    {
        cout<<"There is no mode.\n";
    }
    else if(size==1)
    {
        cout<<"The mode is: "<<array[0]<<".\n";
    }
    else
    {
        cout<<"The modes are: ";
        outputArray(array, size);
    }
}