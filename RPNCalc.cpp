// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 4

// Implementation for RPNCalc Class

#include "RPNCalc.h"

// Default Constructor
RPNCalc::RPNCalc(){
    calcStack = new GenStack<int>();
}

// Overloaded Constructor
RPNCalc::RPNCalc(GenStack<int> gg){
    calcStack = &gg;
}

// Destructor
RPNCalc::~RPNCalc(){
    delete calcStack;
}

// Purpose: Evaluates the RPN calculation
// Parameters: s as a string representing the RPN calculation
// Returns: An int representing the final calculation
int RPNCalc::evaluate(string s){
    int a;
    int b;
    int locate = 1;
    string currIndex;
    string tempStr;
    int countCheck;
    
    if(checkEqn(s) != true){
        throw runtime_error("Not a valid equation!");
    }
    
    while (locate > 0){
        for(int i = 0; i < s.length(); ++i){
            locate = int (s.find(" "));
            currIndex = s.substr(0,locate);
            if( (checkSign(currIndex) == true) ){
                if ((countCheck % 2 == 0)){
                    throw runtime_error("Not a valid equation!");
                }
                a = calcStack->pop();
                b = calcStack->pop();
                calcStack->push(returnMath(a, b, currIndex));
                
            } else {
                calcStack->push(stoi(currIndex));
                countCheck++; 
            }

            s.erase(0, locate + 1);
        }
    }
   
    return calcStack->peek();
}



// Purpose: Checks whether the passed in equation is valid
// Parameters: c as a string
// Returns: Boolean representing whether equation is valid (true)
bool RPNCalc::checkEqn(string c){
    int locate = 1;
    int numOperators = 0;
    int numOperands = 0;
    string tempStr;
    
    while(locate > 0){
        locate = int (c.find(" "));
        tempStr = c.substr(0,locate);
        
        if(checkSign(tempStr) == true){
            numOperators++;
        } else if(isdigit(tempStr[0])){
            numOperands++;
        } else{
            return false;
        }
        c.erase(0, locate+1);
    }

    int check = numOperands - 1;
    
    if(numOperators == check){
        return true;
    } else{
        return false;
    }
    
}

// Purpose: Check whether the string is an operator or operand
// Parameters: s as a string representing the operator, operand, or neither
// Returns: A boolean, where 1 will return if the string is an operator or 0 will return if the string is an operand
bool RPNCalc::checkSign(string c){
    if(c.compare("+") == 0){ //www.cplusplus.com/reference/string/string/compare/
        return true;
    }
    if(c.compare("-") == 0){
        return true;
    }
    if(c.compare("*") == 0){
        return true;
    }
    if(c.compare("/") == 0){
        return true;
    }
    if(c.compare("%") == 0){
        return true;
    }
    return false;
};

// Purpose: Calculates the expression between two numbers given the operator
// Parameters: a as an int representing the first operator, b as an int representing the second operator, c as a string representing the operator
// Returns: An int representing the calculated answer
int RPNCalc::returnMath(int a, int b, string c){
    if(c.compare("+") == 0){
        return add(b,a);
    } else if(c.compare("-") == 0){
        return subtract(b,a);
    } else if(c.compare("*") == 0){
        return multiply(b,a);
    } else if(c.compare("/") == 0){
        return divide(b,a);
    } else if(c.compare("%") == 0){
        return modulo(b, a);
    } else{
        throw runtime_error("Not a valid operator!");
        return -1;
    }
 
}

// Purpose: Adds two operators
// Parameters: a as an int representing the first operator, b as an int representing the second operator
// Returns: An int representing the calculated answer
int RPNCalc::add(int a, int b){
    return a + b;
};

// Purpose: Subtracts two operators
// Parameters: a as an int representing the first operator, b as an int representing the second operator
// Returns: An int representing the calculated answer
int RPNCalc::subtract(int a, int b){
    return a - b;
};

// Purpose: Multiplies two operators
// Parameters: a as an int representing the first operator, b as an int representing the second operator
// Returns: An int representing the calculated answer
int RPNCalc::multiply(int a, int b){
    return a * b;
};

// Purpose: Divides two operators
// Parameters: a as an int representing the first operator, b as an int representing the second operator
// Returns: An int representing the calculated answer
int RPNCalc::divide(int a, int b){
    if(b == 0){
        throw runtime_error("Cannot divide by 0!");
    }
    return a / b;
};

// Purpose: Modulos two operators
// Parameters: a as an int representing the first operator, b as an int representing the second operator
// Returns: An int representing the calculated answer
int RPNCalc::modulo(int a, int b){
    if(b == 0){
        throw runtime_error("Cannot divide by 0!");
    }
    return a % b;
};
