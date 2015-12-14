/* 
 * File:   Vector.h
 * Author: joey
 *
 * Created on December 11, 2015, 12:42 PM
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstdlib>

class Vector {
private:
    vector<int> numbers;
public:
    Vector();
    Vector(const Vector& orig);
    virtual ~Vector();
    void obtainValues();
    void outputArray(int num[], int size); 
    void outputVector(vector<int>,int);
    void sort(int num[], int size); 
    vector<int> top(vector<int>,int);
    void mean(int num[], int size);
    void findMode(int num[], int size);
    int findMaxRepeat(int num[], int size);
    int findModeCount(int num[], int size, int maxRepeat);
    void displayMode(int num[], int size);
};

#endif /* VECTOR_H */

