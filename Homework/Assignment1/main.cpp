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

//Global Constants

//Function Prototypes


//Execution Begins Here
int main(){
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
    Arrays a(10);
    a.prntD1ary();
    a.prntD2ary();
    return 0;
}
