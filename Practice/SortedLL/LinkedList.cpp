/* 
 * File:   LinkedList.cpp
 * Author: rcc
 * 
 * Created on December 8, 2015, 4:25 PM
 */
#include <stdio.h>
#include "LinkedList.h"

LinkedList::LinkedList(){
    head=NULL;
    mode=NULL;
    listSize=0;
}

LinkedList::LinkedList(const LinkedList& orig) {
    this->head=orig.head;
    this->listSize=orig.listSize;
}

LinkedList::~LinkedList() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
}

int* LinkedList::TopNums(int&p){
    if(p>listSize){
        p=listSize;
    }
    static int* top = new int [p];
    Node* temp = head;
    for(int i=0; i<p; i++){
        top[i]=temp->x;
        temp=temp->next;
    }
    return top;
}

void LinkedList::Push(int n){
    Node* push = new Node();
    push->x=n;
    push->next=NULL;
    Node *temp = head;
    
    if(head==NULL){
//        printf("head is null\n");
        head=push;
    } else if(head->next==NULL){
//        printf("only one element in list\n");
        //Only one node in list
        if(push->x < temp->x){
            head=push;
            push->next=temp;
        } else{
            temp->next=push;
        }
    } else{
        // Holds the node previous to temp
        Node* prev = NULL;
        // Compare with temp and traverse until temp is the first element n is 
        // less than
        while(temp!=NULL && push->x > temp->x){
            //Initialize prev as head once temp moves once
            if(!prev){
                prev=head;
            } else{
                prev=prev->next;
            }
            temp = temp->next;
        } 
        if(temp==head){
            //Append to beginning of list
            push->next=head;
            head=push;
        } else{
            //Append before temp and after prev
            push->next=temp;
            prev->next=push;
        }
    }
    listSize++;
}

void LinkedList::findMode(){
    int maxRepeat = findMaxRepeat(); 
    if(maxRepeat==1){
        displayMode(0,0);
        return;
    }
    int modeCount = findModeCount();
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

int LinkedList::findMaxRepeat(){
    Node* temp = head;
    int number = temp;
    int repeat = 1;
    int maxRepeat = 1;
    for (int i=1; i<=listSize; i++){
        if(temp == number){
            repeat++;
            temp=temp->next;
        } else{
            if(repeat>maxRepeat){
                maxRepeat=repeat;
            }
            temp=temp->next;
            repeat = 1;
            number = temp;
        }
    }
    return maxRepeat;
}

int LinkedList::findModeCount(){
    int modeCount = 0;
    int repeat = 1;
    int number = num[0];
    for (int i=1; i<=size; i++){
        if(num[i] == number){
            repeat++;
        } else{
            if(repeat == maxRepeat){
                modeCount++;
            }
            repeat = 1;
            number = num[i];
        }
    }
    return modeCount;
}

void LinkedList::displayMode(){
    if(size==0){
        printf("There is no mode.\n");
    } else if(size==1){
        printf("The mode is: %d.\n",array[0]);
    } else{
        printf("The modes are: ");
        outputArray(array, size);
    }
}

void LinkedList::Print(){
    Node *temp=head;
    do{
        printf("%d --> ",temp->x);
        temp=temp->next;
    }while (temp!=NULL );
    printf("NULL\n");
}

