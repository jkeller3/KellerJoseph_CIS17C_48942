/* 
 * File:   Hashing.h
 * Author: rcc
 *
 * Created on December 16, 2015, 5:56 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string>

using namespace std;

#ifndef HASHING_H
#define	HASHING_H

class Hashing {
private:
    static const int tableSize = 512;
    int collision;
    struct Item{
        char* name;
        int intName;
        int coll;
        Item* next;
    };
    Item* HashTable[tableSize];
public:
    Hashing();
    Hashing(const Hashing& orig);
    virtual ~Hashing();
    void Hash(char*);
    int GetHash(int);
    int GetPhoneNum(char);
    void Print();
};

#endif	/* HASHING_H */

