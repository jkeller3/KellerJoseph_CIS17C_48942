/* 
 * File:   AdjListNode.h
 * Author: rcc
 *
 * Created on December 17, 2015, 3:06 PM
 */


#ifndef ADJLISTNODE_H
#define	ADJLISTNODE_H
#include <string>
using namespace std;
struct AdjListNode{
    int index;
    string dest;
    int dist;
    struct AdjListNode* next;
};

#endif	/* ADJLISTNODE_H */

