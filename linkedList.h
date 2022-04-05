// Nathan Nguyen
// 2370739
// nnguyen1@chapman.edu
// CPSC350 - 01
// Assignment 4


// LinkedList Template Class
// Reused and modified from Lecture

#ifndef linkedList_h
#define linkedList_h

#include <iostream>
#include <exception>

using namespace std;


template<class T>
class ListNode{
    
public:
    ListNode();
    ListNode(T data);
    ~ListNode();
    
    ListNode<T> *next;
    ListNode<T> *prev;
    T data;
    
};

//implementation

// Default Constructor
template <class T>
ListNode<T>::ListNode(){
    next = NULL;
}

// Overloaded Constructor
template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}


// Destructor
template <class T>
ListNode<T>::~ListNode(){
    next = NULL;
}

template <class T>
class DoublyLinkedList{
private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T deleteAtPos(int pos);
    T peek();
    T peekAtPos(int pos);
    ListNode<T>* removeNode(T value);
    int find(T value); //search()
    bool isEmpty();
    unsigned int getSize();
    
};

//implementation

// Default Constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    size = 0;
    front = NULL;
    back = NULL;
}


// Destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while(isEmpty() != 1){
        T data = removeFront();
        delete front;
    }
}

// Purpose: Inserts node in the front of linkedlist
// Parameters: d as type T
// Returns: no returns
template <class T>
void DoublyLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);
    
    if(isEmpty()){
        back = node;
    } else{
        // not an empty list
        node->next = front;
    }
    front = node;
    ++size;
}

// Purpose: Inserts node in the back of linkedlist
// Parameters: d as type T
// Returns: no returns
template <class T>
void DoublyLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);
    
    if(isEmpty()){
        front = node;
    } else{
        //not empty
        node->prev = back;
        
    }
    
    ++size;
    
}

// Purpose: Removes node in front of linkedlist
// Parameters: none
// Returns: tdata as type T representing the data of the removed node
template <class T>
T DoublyLinkedList<T>::removeFront(){
    
    if(isEmpty()){
        throw runtime_error("Linkedlist is empty; cannot remove front!");
    }
    ListNode<T> *temp = front;
    
    if(front->next == NULL){
        back = NULL;
    } else{
        // we have more than 1 ListNode, list size > 1
        front->next->prev = NULL;
    }
    
    front = front->next;
    T tdata = temp->data;
    temp->next = NULL;
    --size;
    delete temp;
    
    return tdata;
}

// Purpose: Removes node in back of linkedlist
// Parameters: none
// Returns: data as type T representing the data of the removed node
template <class T>
T DoublyLinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("Linkedlist is emptyl cannot remove back!");
    }
    
    ListNode<T> *temp = back;
    if(back->prev == NULL){
        //only one node in the list
        front = NULL;
    } else{
        // more than one node in the list
        back->prev->next = NULL;
    
    }
    back = back->prev;
    T data = temp->data;
    
    temp->prev = NULL;
    --size;
    delete temp;
    
    return data;
}

// Purpose: Finds the node with the specific data value
// Parameters: value as type T
// Returns: An int representing the position of the found node
template <class T>
int DoublyLinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;
    
    while(curr != NULL){
        ++pos;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }
    if(curr==NULL){
        pos = -1;
    }
    
    return pos;
}

// Purpose: Takes a "peek" at the data stored in the front node
// Parameters: none
// Returns: d as type T representing the data of the node
template <class T>
T DoublyLinkedList<T>::peek(){
    if(isEmpty()){
        throw runtime_error("Linkedlist is empty, can not peek!");
    }
    T d = front->data;
    return d;
}

// Purpose: Takes a "peek" at the data stored at the node in the specified position
// Parameters: pos as an in represnting the position of the desired node
// Returns: d as type T representing the data of the node
template <class T>
T DoublyLinkedList<T>::peekAtPos(int pos){
    if(isEmpty()){
        throw runtime_error("Linkedlist is empty, can not peek!");
    }
    int nodePosition = 0;
    
    ListNode<T> *curr = front;
    
    while(nodePosition != pos){
        curr = curr->next;
        ++nodePosition;
    }
    
    //this point prev and curr should be in the correct spots
    T d = curr->data;
    return d;
}

// Purpose: Determines if the linkedlist is empty
// Parameters: none
// Returns: Boolean represnting whether the linkedlist is empty
template <class T>
bool DoublyLinkedList<T>::isEmpty(){
    return(size == 0);
}

// Purpose: Gets the size of the linkedlist
// Parameters: none
// Returns: Unsigned int represnting the size of the linkedlist
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

// Purpose: Deletes node at desired position
// Parameters: pos as an int represnting the position of the desired node to be removed
// Returns: d as type T representing the data of the removed node
template <class T>
T DoublyLinkedList<T>::deleteAtPos(int pos){
    if(isEmpty()){
        throw runtime_error("Linkedlist is empty, can not delete!");
    }
    int nodePosition = 0;
    
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;
    
    while(nodePosition != pos){
        prev = curr;
        curr = curr->next;
        ++nodePosition;
    }
    
    //this point prev and curr should be in the correct spots
    prev->next = curr->next;
    curr->next = NULL;
    T d = curr->data;
    --size;
    delete curr;
    return d;
}


// Purpose: Removes node with a specific value
// Parameters: value as type T
// Returns: temp as the pointer to the ListNode removed
template <class T>
ListNode<T>* DoublyLinkedList<T>::removeNode(T value){
    if(isEmpty()){
        throw runtime_error("Linkedlist is empty, can not remove node!");
    }
    
    // leverage the find method
    ListNode<T> *curr = front;
    
    
    while(curr->data != value){
        curr = curr->next;
        
        if(curr == NULL)
            throw runtime_error("A node with that value does not exist.");
        
    }
    
    // we found the node and now curr is in the correct position
    if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }
    if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }
    if(curr != front  && curr != back){
        //listNode is between front and back
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }
    
    curr->next = NULL;
    curr->prev = NULL;
    
    int temp = curr->data;
    --size;
    delete curr;
    
    return temp;
}

#endif /* linkedList_h */
