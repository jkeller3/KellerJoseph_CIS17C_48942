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
    modeCount=0;
}

LinkedList::LinkedList(const LinkedList& orig) {
    this->head=orig.head;
    this->listSize=orig.listSize;
    this->mode=orig.mode;
    this->modeCount=orig.modeCount;
}

LinkedList::~LinkedList() {
    for(int i=0; i<listSize; i++){
        Node* temp = head->next;
        delete head;
        head=temp;
    }
    for(int i=0; i<modeCount; i++){
        Node* temp = mode->next;
        delete mode;
        mode=temp;
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

void LinkedList::FindMode(){
    Node* temp = head;
    int maxRepeat = FindMaxRepeat();
    if(maxRepeat==1){
        DisplayMode();
        return;
    }
//    int modeCount = FindModeCount(maxRepeat);
    int repeat=1;
    Node* prev = head;
    temp=temp->next;
    while(prev!=NULL){
        if(temp->x == prev->x){
            repeat++;
        }
        else{
            if(repeat == maxRepeat){
                Node* add = new Node();
                add->x=prev->x;
                add->next=mode;
                mode=add;
                modeCount++;
            }
            repeat = 1;
        }
        prev=prev->next;
        if(temp!=NULL){
            temp=temp->next;
        }
    }
    DisplayMode();
}

int LinkedList::FindMaxRepeat(){
    Node* temp = head;
    Node* prev = head;
    int repeat = 1;
    int maxRepeat = 1;
    temp=temp->next;
    while(prev!=NULL){
        if(temp->x == prev->x){
            repeat++;
        }
        else{
            if(repeat>maxRepeat){
                maxRepeat=repeat;
            }
            repeat = 1;
        }
        prev=prev->next;
        if(temp!=NULL){
            temp=temp->next;
        }
    }
    return maxRepeat;
}

//int LinkedList::FindModeCount(int maxRepeat){
//    Node* temp = head;
//    int modeCount = 0;
//    int repeat = 1;
//    int number = temp->x;
//    temp=temp->next;
//    for (int i=1; i<listSize; i++){
//        if(temp->x == number){
//            repeat++;
//        }
//        else{
//            if(repeat == maxRepeat){
//                modeCount++;
//            }
//            repeat = 1;
//            number = temp->x;
//        }
//        temp=temp->next;
//    }
//    return modeCount;
//}

void LinkedList::DisplayMode(){
    if(modeCount==0){
        printf("There is no mode.\n");
    }
    else if(modeCount==1){
        printf("The mode is: %d.\n",mode->x);
    }
    else{
        printf("The modes are: ");
        while(mode!=NULL){
            printf("%d ",mode->x);
            mode=mode->next;
        }
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