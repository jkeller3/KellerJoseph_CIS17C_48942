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
    Arrays<int> a(10);
    a.filD1ary();
    a.filD2ary();
    a.prntD1ary();
    a.prntD2ary();
    return 0;
}
