/* 
 * File:   Hashing.cpp
 * Author: rcc
 * 
 * Created on December 16, 2015, 5:56 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <vector>

using namespace std;

#include "Hashing.h"

Hashing::Hashing() {
    for(int i=0; i<tableSize; i++){
        HashTable[i] = new Item;
        HashTable[i]->name = new char [3];
        strcpy(HashTable[i]->name,"---");
        HashTable[i]->intName = 0;
        HashTable[i]->next = NULL;
    }
    collision = 0;
}

Hashing::Hashing(const Hashing& orig) {
}

Hashing::~Hashing() {
}

void Hashing::Hash(char* key){
    int nKey1 = GetPhoneNum(key[0])*100;
    int nKey2 = GetPhoneNum(key[1])*10;
    int nKey3 = GetPhoneNum(key[2]);
    int firstKey = nKey1+nKey2+nKey3;
    int newKey=GetHash(firstKey);
    if(HashTable[newKey]->name[0]='-'){
        HashTable[newKey]->name = key;
        HashTable[newKey]->intName = firstKey;
    } else if(HashTable[newKey]->next!=NULL){
        Item* temp = HashTable[newKey];
        while(temp!=NULL){
            temp = temp->next;
        }
        Item* newNode = new Item;
        newNode->name = key;
        newNode->intName = firstKey;
        newNode->next = NULL;
        temp->next = newNode;
        collision++;
        HashTable[newKey]->coll++;
    } else{
        Item* newNode = new Item;
        newNode->name = key;
        newNode->intName = firstKey;
        newNode->next = NULL;
        HashTable[newKey]->next = newNode;
        collision++;
        HashTable[newKey]->coll++;
    }
}

int Hashing::GetHash(int key){
    if(key<300){
        return key%88;
    } else if(key<400){
        return (key%88)+88;
    } else if(key<500){
        return (key%88)+176;
    } else if(key<600){
        return (key%88)+264;
    } else if(key<700){
        return (key%88)+352;
    } else if(key<800){
        return ((key%88)+440)%512;
    } else if(key<900){
        return ((key%88)+528)%512;
    } else{
        return ((key%88)+616)%512;
    }
}

int Hashing::GetPhoneNum(char key){
    if(key=='A'||key=='B'||key=='C'){
        return 2;
    } else if(key=='D'||key=='E'||key=='F'){
        return 3;
    } else if(key=='G'||key=='H'||key=='I'){
        return 4;
    } else if(key=='J'||key=='K'||key=='L'){
        return 5;
    } else if(key=='M'||key=='N'||key=='O'){
        return 6;
    } else if(key=='P'||key=='Q'||key=='R'||key=='S'){
        return 7;
    } else if(key=='T'||key=='U'||key=='V'){
        return 8;
    } else{
        return 9;
    }
}

void Hashing::Print(){
    for(int i=0; i<tableSize; i++){
        printf("HashTable[%d]: \n",i);
        printf("Name: %s\n",HashTable[i]->name);
        printf("IntNum: %d\n",HashTable[i]->intName);
        printf("Collisions: %d\n",HashTable[i]->coll);
    }
}