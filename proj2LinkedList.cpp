//
//  LinkedList.cpp
//  StacksAndQueues
//
//  Created by Bradley Turner on 2/20/18.
//  Copyright © 2018 Bradley Turner. All rights reserved.
//

#include "proj2LinkedList.hpp"

void LinkedList :: tailInsert(float coeff, int exp){
        intNode *temp = new intNode();
        temp->exp = exp;
        temp->coeff = coeff;
        temp->next = NULL;
        if(head == NULL){
            head = tail = temp;
            count++;
        }else{
            tail->next = temp;
            tail = temp;
            temp = NULL;
            count++;
        };
}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}
void LinkedList:: headRemove(){
    if(size() > 0){
        head = head->next;
        count--;
    }else throw logic_error("Cannot remove from empty list");
}
void LinkedList:: tailRemove(){
    if(size() > 0){
        intNode *temp;
        temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
    }else throw logic_error("Cannot remove from empty list");
}
LinkedList::LinkedList(const LinkedList* copyLst){
    const intNode *cpCurrent = copyLst->head;
    intNode *lsCurrent = NULL;
    if (cpCurrent != NULL) {
        head = new intNode();
        head->exp = cpCurrent -> exp;
        head->coeff = cpCurrent->coeff;
        lsCurrent = head;
        cpCurrent = cpCurrent -> next;
        count++;
    }
    while (cpCurrent != NULL) {
        intNode *newNode = new intNode();
        newNode->exp = cpCurrent->exp;
        newNode->coeff = cpCurrent->coeff;
        lsCurrent -> next = newNode;
        lsCurrent = lsCurrent -> next;
        cpCurrent = cpCurrent -> next;
        count++;
    }
}

LinkedList::~LinkedList(){
    clear();
}

void LinkedList :: headInsert(float coeff, int exp){
        intNode *temp = new intNode();
        temp->exp = exp;
        temp->coeff = coeff;
        temp->next = head;
        if(head == NULL){
            head = tail = temp;
        }else{
            head = temp;
        }
        count++;
}

int LinkedList :: size(){
    return count;
}

string LinkedList :: toString(){
    intNode *temp = new intNode();
    temp = head;
    string str = "[";
    while(temp != NULL){
        if(temp->next != NULL){
        str += to_string(temp->coeff) + "x" + "^" + to_string(temp->exp) +  + " + ";
        } else str += to_string(temp->coeff) + "x" + "^" + to_string(temp->exp) + "]\n";
        temp = temp->next;
    }
    if(str == "["){
        return "[EMPTY]\n";
    }else return str;
}


void LinkedList :: clear(){
    head = NULL;
    count = 0;
}

bool LinkedList :: empty(){
    return head == NULL;
}

void LinkedList :: posInsert(int pos, float coeff, int exp){
    if(pos > size()){
            throw logic_error("Cannot position insert past the end of the list, it would leave holes");
        }
        intNode *pre=new intNode;
        intNode *cur=new intNode;
        intNode *temp=new intNode;
        cur=head;
        for(int i=1;i<pos;i++){
            pre=cur;
            cur=cur->next;
        }
        temp->exp=exp;
        temp->coeff = coeff;
        pre->next=temp;
        temp->next=cur;
        count++;
}


intNode LinkedList :: retrieve(int pos){
    pos -= 1;
    intNode *node = new intNode;
    node = head;
    if(pos > size()){
        throw logic_error("Position entered is not yet filled in the list, retrieval would result in a garbage value. List size = " + to_string(size()));
    }else{
        for(int i = 0; i < pos; i++){
            node = node->next;
        }
        return *node;
    }
}

void LinkedList ::  posRemove(int pos){
    if(pos > 0)
        pos-=1;
    if(pos > size()){
        throw logic_error("Position entered is not yet filled in the list, retrieval would result in a garbage value. List size = " + to_string(size()));
    }
    if (head == NULL)
    return;
    
    intNode *temp = head;
    if (pos == 0)
    {
        head = temp->next;
        free(temp);
        count--;
        return;
    }
    for (int i=0; temp!=NULL && i<pos-1; i++)
    temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    return;
    if(temp->next == tail){
        tail = temp;
    }
    intNode *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    count--;
}

LinkedList& LinkedList :: operator=(LinkedList &list){
    const intNode *cpCurrent = list.head;
    intNode *lsCurrent = NULL;
    if (cpCurrent != NULL) {
        head = new intNode();
        head->exp = cpCurrent -> exp;
        head->coeff = cpCurrent -> coeff;
        lsCurrent = head;
        cpCurrent = cpCurrent -> next;
        count++;
    }
    while (cpCurrent != NULL) {
        intNode *newNode = new intNode();
        newNode->exp = cpCurrent->exp;
        newNode->coeff = cpCurrent->coeff;
        lsCurrent -> next = newNode;
        lsCurrent = lsCurrent -> next;
        cpCurrent = cpCurrent -> next;
        count++;
    }
    return *this;
}

void LinkedList :: replace(int pos, float coeff, int exp){
    pos -= 1;
    if(pos > size()){
        throw logic_error("Position entered is not yet filled in the list, retrieval would result in a null pointer. List size = " + to_string(size()));
    }
    intNode *temp = head;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }
    temp->exp = exp;
    temp->coeff = coeff;
}


