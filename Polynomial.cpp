//
//  Polynomial.cpp
//  ESE344_Project_2
//
//  Created by Bradley Turner on 3/22/18.
//  Copyright © 2018 Bradley Turner. All rights reserved.
//

#include "Polynomial.hpp"
#include <iostream>
typedef intNode Term;
using namespace std;

bool isNum(string a);
bool isInt(string a);

Polynomial :: Polynomial(){}

Polynomial& Polynomial :: operator= (Polynomial &toAssign){
    polynom = toAssign.polynom;
    return *this;
}

void Polynomial :: multiply_by_term(Term multiplier){
    Term *current = polynom.head;
    while(current != NULL){
        current->coeff *= multiplier.coeff;
        current->exp += multiplier.exp;
        current = current->next;
    }
}

void Polynomial :: product(Polynomial q){
    LinkedList temp;
    temp = polynom;
    Polynomial product;
    Term *qCurrent = q.polynom.head;
    Term *thisCurrent = polynom.head;
    while(qCurrent != NULL){
        multiply_by_term(*qCurrent);
        while(thisCurrent != NULL){
            product.polynom.headInsert(thisCurrent->coeff, thisCurrent->exp);
            thisCurrent = thisCurrent ->next;
        }
        polynom = temp;
        thisCurrent = polynom.head;
        qCurrent = qCurrent->next;
    }
    insertionSort(&product.polynom.head);
    addLikeTerms(&product.polynom.head);
    polynom = product.polynom;
    
}

//used by insertion sort
void Polynomial :: sortedInsert(Term **head_ref, Term *new_node){
    Term *current;
    if (*head_ref == NULL || (*head_ref)->exp <= new_node->exp)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else{
        current = *head_ref;
        while (current->next!=NULL && current->next->exp > new_node->exp){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void Polynomial :: insertionSort(Term **headRef){
    Term *sorted = NULL;
    Term *current = *headRef;
    while (current != NULL)
    {
        Term *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *headRef = sorted;
}
//reads and sorts no need to input your exponents in any specific
//order
void Polynomial :: read(){
    float coeff;
    int exp;
    cout << "Enter the coefficients and exponents for your polynomial:\n";
    do{
        string temp;
        do{
        cout << "Coefficient?" << flush;
        cin >> temp;
        }while(!isNum(temp));
        coeff = stoi(temp);
        if(coeff == 0) break;
        do{
        cout << "Exponent?" << flush;
        cin >> temp;
        }while(!isInt(temp));
        exp = stoi(temp);
        polynom.tailInsert(coeff, exp);
    }while(coeff != 0);
    insertionSort(&polynom.head);
    addLikeTerms(&polynom.head);
    cout << endl << endl << endl;
}

void Polynomial :: addLikeTerms(Term **headRef){
    Term *current = *headRef;
    while(current -> next != NULL){
        if(current->exp == current->next->exp){
            current->coeff += current->next->coeff;
            current->next = current->next->next;
        }
        if(current->next != NULL && current->exp != current ->next->exp){
            current = current->next;
        }
    }
}

void Polynomial :: add(Polynomial q){
    Term *current = q.polynom.head;
    while(current != NULL){
        polynom.headInsert(current->coeff, current->exp);
        current = current -> next;
    }
    insertionSort(&polynom.head);
    addLikeTerms(&polynom.head);
}

bool isNum(string a){
    bool result = true;
    for(int i = 0; i < a.length(); i++){
        if((!isnumber(a.at(i)) && !(a.at(i) == '.') && !(a.at(i) == '-' && i == 0))){
            return false;
        }
    }
    return result;
}

bool isInt(string a){
    bool result = true;
    for(int i = 0; i < a.length(); i++){
        if(!isnumber(a.at(i)) && !(a.at(i) == '-' && i == 0)){
            return false;
        }
    }
    return result;
}

string Polynomial :: toString(){
    return polynom.toString();
}
