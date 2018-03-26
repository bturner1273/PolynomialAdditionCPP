//
//  main.cpp
//  ESE344_Project_2
//
//  Created by Bradley Turner on 2/27/18.
//  Copyright © 2018 Bradley Turner. All rights reserved.
//
#include <iostream>
#include "Polynomial.hpp"
using namespace std;
bool isNum(string a);

int main(int argc, const char * argv[]) {
    Polynomial a;
    a.read();
    cout << "Polynomial A = " << a.toString();
    Polynomial b;
    b.read();
    cout << "Polynomial B = " << b.toString();
    a.product(b);
    cout << endl << endl << "Polynomial A * B = " << a.toString();

}

/* TEST CODE
 
 to test first copy the below block initializing polynomial a
 then you can copy and paste any test code chunk below
 
 //    Polynomial a;
 //    a.read();
 
 
 Tests the add like terms method (before I put it at the end of the read method)
 //    cout << a.toString();
 //    std::cout << std::boolalpha;
 //    cout << isNum("1100") << "\n";
 //    cout << "Before adding like terms " << a.toString();
 //    a.addLikeTerms(&a.polynom.head);
 //    cout << "After adding like terms " << a.toString();
 
 Tests addition of two polynomials
 //    cout << "A before adding 5x^3 + 2x^2: " << a.toString();
 //    Polynomial b;
 //    b.polynom.headInsert(2, 2);
 //    b.polynom.headInsert(5, 3);
 //    a.add(b);
 //    cout << "A after adding 5x^3 + 2x^2: " << a.toString();
 //    cout << "A before multiplying by 2x^2: " << a.toString();
 
 Tests multiplication of a polynomial by a single term
 //    Term b = {
 //        2,
 //        -2,
 //        NULL
 //    };
 //    a.multiply_by_term(b);
 //    cout << "A after multiplying by -2x^2: " << a.toString();
 //
 
 Testing polynomial multiplication
 //    Polynomial p;
 //    p.polynom.headInsert(2, 2);
 //    p.polynom.headInsert(2, 2);
 //    p.addLikeTerms(&p.polynom.head);
 //    a.product(p);
 //    cout << a.toString();
 //
 */


