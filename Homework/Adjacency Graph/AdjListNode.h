/* 
 * File:   AdjListNode.h
 * Author: rcc
 *
 * Created on December 14, 2015, 4:53 PM
 */

#ifndef ADJLISTNODE_H
#define	ADJLISTNODE_H

struct AdjListNode{
    int dest;
    int dist;
    struct AdjListNode* next;
};


#endif	/* ADJLISTNODE_H */

