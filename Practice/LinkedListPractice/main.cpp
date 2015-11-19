#include <cstdlib>
#include <iostream>
using namespace std;

struct node{
    int x;
    node* next;
};

int main(int argc, char** argv) {
    node* a;
    a = NULL;
    
    node* temp = new node();
    temp->x=2;
    temp->next=NULL;
    a=temp;
    
    temp=new node();
    temp->x=4;
    temp->next=NULL;
    
    node* temp1=a;
    while(temp1->next!=NULL){
        cout<<temp1->x;
        temp1=temp1->next;
    }
    temp1->next=temp;
    

    return 0;
}

