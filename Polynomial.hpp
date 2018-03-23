//
//  Polynomial.hpp
//  ESE344_Project_2
//
//  Created by Bradley Turner on 3/22/18.
//  Copyright © 2018 Bradley Turner. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include "proj2LinkedList.hpp"
typedef intNode Term;

#endif /* Polynomial_hpp */


class Polynomial{
public:
    LinkedList polynom;
    void read(void);
    string toString(void);
    Polynomial();
    Polynomial& operator=(Polynomial &toAssign);
    void add(Polynomial q); //adds another polynomial to this.polynom
    void addLikeTerms(Term **headRef); //adds like terms in this.polynom
    void insertionSort(Term **headRef); //sorts this.polynom in decreasing order
                                        //of exps
    void sortedInsert(Term **head_ref, Term *new_node); //used by insertion sort
    void multiply_by_term(Term multiplier); //multiplies entier polynomial by one term
    void product(Polynomial q); //this polynomial *= q (polynomial multiplication)
};
