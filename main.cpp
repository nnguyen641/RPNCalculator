// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 4

#include <iostream>
#include "GenStack.h"
#include "RPNCalc.h"

int main(int argc, char** argv) {
    try{

        // Executes RPN calculator 
        
        RPNCalc currCalc;
        string userInput;
        cout << "Welcome to the Post-Fix Notation Calculator!" << endl;    
        cout << "Enter the operands and operators separated by spaces." << endl;
        getline(cin, userInput);
            
        cout << endl << "Calculating..." << endl << endl;

        cout << "Answer: " << currCalc.evaluate(userInput) << endl;;
        cout << "Thank you. Have a nice day!" << endl;
        
    } catch(runtime_error &except){
        cerr << except.what() << endl;
    }
}
