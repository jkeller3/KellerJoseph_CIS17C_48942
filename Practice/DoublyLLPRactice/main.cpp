/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on December 2, 2015, 5:11 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Stack.h"

int main(int argc, char** argv) {

    Stack list;
    list.Push(3);
    list.Push(5);
    list.Push(10);
    list.Print();
    return 0;
}

