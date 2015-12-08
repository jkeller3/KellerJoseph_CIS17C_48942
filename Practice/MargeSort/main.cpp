#include <iostream>
using namespace std;
 
 
void print(int * a, int s) {
  for (int i = 0; i < s; i++)
    cout << a[i] << ", ";
  cout << endl;
}
 
 
int* merge(int* a1, int* a2, int s1, int s2){
    int* a3 = new int [s1+s2];
    int i=0, j=0;
    while(i < s1 && j < s2){
        if(a1[i]>a2[j]){
            a3[i+j]=a2[j];
            j++;
        }
        else{
            a3[i+j]=a1[i];
            i++;
        }
    }
    while(i < s1) {
        a3[i+j]=a1[i];
        i++;
    }
    while(j < s2) {
        a3[i+j]=a2[j];
        j++;
    }
    return a3;
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
 
 
int main() {
  int s = 10;
  int * a = new int[s];
  a[0] = 6;
  a[1] = 2;
  a[2] = 4;
  a[3] = 12;
  a[4] = 5;
  a[5] = 2;
  a[6] = 7;
  a[7] = 90;
  a[8] = 2;
  a[9] = 10;
  print(a, s);
  int * b = mergeSort(a, s);
  print(b, s);
}