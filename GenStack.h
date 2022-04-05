// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 4

// GenStack Template Class using LinkedList
// Inspired and modified from Lecture

#ifndef GenStack_h
#define GenStack_h

#include <iostream>
#include <exception>
#include "linkedList.h"

using namespace std;

template<class T>
class GenStack{
    public:
        GenStack(); // constructor
        ~GenStack(); // destructor
    
        //core functions
        void push(T data);
        T pop();
    
        //aux/helper functions
        T peek();
        bool isEmpty();
        int getSize();
        void printStack();
    
    
    private:
        DoublyLinkedList<T> *myList;
};

// Default Constructor
template <class T>
GenStack<T>::GenStack(){
    myList = new DoublyLinkedList<T>();
}

// Destructor
template <class T>
GenStack<T>::~GenStack(){
    delete myList;
}

// Purpose: Inserts element onto stack
// Parameters: data as type T
// Returns: no returns
template <class T>
void GenStack<T>::push(T data){
    myList->insertFront(data);
}

// Purpose: "Peeks" node on top of stack
// Parameters: none
// Returns: element of type T
template <class T>
T GenStack<T>::peek(){
    if(isEmpty()){
        throw runtime_error("Stack is empty, can NOT peek!!");
    }
    
    return myList->peek();
}

// Purpose: Removes node on top of the stack
// Parameters: none
// Returns: element of type T
template <class T>
T GenStack<T>::pop(){
    // check if empty
    if(isEmpty()){
        throw runtime_error("Stack is empty, can NOT pop!!");
    }
    
    return myList->removeFront();
}

// Purpose: Checks whether the stack is empty
// Parameters: none
// Returns: Boolean representing whether stack is empty (1 is empty, 0 is not empty)
template <class T>
bool GenStack<T>::isEmpty(){
    return myList->isEmpty();
}

// Purpose: Gets the number of elements in the stack
// Parameters: none
// Returns: An int representing the number of elements
template <class T>
int GenStack<T>::getSize(){
    return myList->getSize();
}

// Purpose: Prints the elements of the stack
// Parameters: None
// Returns: None
template <class T>
void GenStack<T>::printStack(){
    if(isEmpty()){
        throw runtime_error("Stack is empty.");
    }
    int count = getSize();
    for(int i = 0; i < count; ++i){
        cout << myList->peekAtPos(i) << endl;
    }
}

#endif /* GenStack_h */
