//
//  LinkedList.hpp
//  StacksAndQueues
//
//  Created by Bradley Turner on 2/20/18.
//  Copyright © 2018 Bradley Turner. All rights reserved.
//

#ifndef proj2LinkedList_hpp
#define proj2LinkedList_hpp
#include <stdio.h>
#include <iostream>
using namespace std;
#endif /* proj2LinkedList_hpp */

struct intNode{
    int exp, coeff;
    intNode *next;
};
class LinkedList{
public:
    intNode *head, *tail;
    LinkedList();
    LinkedList(const LinkedList* copyLst);
    ~LinkedList();
    void tailInsert(float coeff, int exp);
    void headInsert(float coeff, int exp);
    void tailRemove();
    void headRemove();
    void posInsert(int pos, float coeff, int exp);
    string toString();
    void clear();
    bool empty();
    int size();
    bool full();
    intNode retrieve(int pos);
    void posRemove(int pos);
    void replace(int pos, float coeff, int exp);
    LinkedList& operator=(LinkedList &list);
private:
    int count = 0;
};
