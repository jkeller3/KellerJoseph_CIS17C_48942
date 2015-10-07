/*
 * Dr Mark E. Lehr
 * Sept 2nd, 2015
 * Purpose:  Tranigular Matrix
 * Hmwk:  Create a templated Class implmented the Matrix
*/

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "arrays.h"
#include "arrays.cpp"

//Global Constants

//Function Prototypes


//Execution Begins Here
int main(){
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    cout<<"How big would you like the float matrix to be?\n";
    int num;
    cin>>num;
    Arrays<float> a(num);
    cout<<"How big would you like the int matrix to be?\n";
    cin>>num;
    Arrays<int> b(num);
    return 0;
}
