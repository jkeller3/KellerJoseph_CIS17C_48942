/* 
 * File:   SelfOrganizingList.cpp
 * Author: joey
 * 
 * Created on December 11, 2015, 12:24 AM
 */
#include <cstdlib>
using namespace std;
#include "SelfOrganizingList.h"
#include "LinkedList.h"

bool SelfOrganizingList::MoveFront(int n){
    bool numExist=false;
    Node* temp = head;
    Node* prev = 0;
 
    while (temp!=NULL){
        if (temp->x==n){
            if (prev != NULL){
                Node* curr = temp->next;
                temp->next=head;
                prev->next=curr;
                temp=prev->next;
                numExist=true;
            } else{
                // prev is null
                numExist=true;
            }
        } else{
            // not n
            prev = temp;
            temp = temp->next;
        }
    }
    return numExist;
}