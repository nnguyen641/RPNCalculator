// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 4

// Header file for RPNCalc Class

#ifndef RPNCalc_h
#define RPNCalc_h

#include <iostream>
#include <exception>
#include <string>
#include "GenStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;


class RPNCalc{
    public:
        RPNCalc(); // default constructor
        RPNCalc(GenStack<int> gg); // overloaded constructor
        ~RPNCalc(); // destructor
    
        bool checkSign(string c);
        int returnMath(int a, int b, string c);
        int evaluate(string s);
        bool checkEqn(string c);
        int checkInt(string n);
        
        int add(int a, int b);
        int subtract(int a, int b);
        int multiply(int a, int b);
        int divide(int a, int b);
        int modulo (int a, int b);
        
    private:
    
        GenStack<int> *calcStack;
        int m_a;
        int m_b;
        int m_c;
        int m_d;
        
};

#endif /* RPNCalc_h */
