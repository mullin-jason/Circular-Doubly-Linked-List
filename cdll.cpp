#include "cdll.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;


// node constructor
node::node(int x_value){
    x = x_value;

    next = NULL;
    prev = NULL;
}

// node deconstructor 
node::~node(){
}

// struc constructor
CDLL::CDLL(){
    head = NULL;
    current = NULL;
    len = 0;
}

// struc  deconstructor
CDLL::~CDLL(){
    // basecase if list is empty
    if(!head)
    {
        return;    
    }

    node *p = head;
    p->prev->next = NULL;
    node *p2;

    // loo*p till list deletes itself
    while(p){  
        p2 = p -> next;
        delete p;
        p = p2;
    }
}

void CDLL::prepend(int x_value){
    // if empty    
    if(head == NULL)
    {
        node* temp = new node(x_value);
        temp -> next = temp -> prev = temp;
        head = temp;
        len += 1;

        return;
    }
   
   node* last = head -> prev; 
   node* temp = new node(x_value);

   temp -> next = head;
   temp -> prev = last; 
   head -> prev = last -> next = temp;

   head = temp;

   len += 1;
}

void CDLL::append(int x_value){
    // base 
    if(head == NULL)
    {
        node* temp = new node(x_value);
        temp -> next = temp -> prev = temp;
        head = temp;  
        len += 1;
        return;
    }

    node* last = head -> prev;
    node* temp = new node(x_value);
    temp -> next = head;
    temp -> prev = last;

    last -> next = head -> prev = temp; 

    len += 1;
}

// helper function for getting next item in list
void CDLL::next(){
    head = head -> next;
    printCurrent();
}

// helper function to get previous item in our list
void CDLL::previous(){
    head = head -> prev;
    printCurrent();
}

// helper to print current head of list
void CDLL::printCurrent(){
    cout<< head -> x;
}

// helper to print all items in our list
void CDLL::printAll(){ 
    int i = 0; 
    while(i < len){
        cout<< head -> x << " ";
        head = head -> next;
        i++;
    }
}

// helper to remove last item in list 
void CDLL::removeLast(){
    if(head == NULL)
    {
        return;
    }
    
    node* last = head -> prev;
    node* temp = last->prev;
    delete(last);
    head -> prev = temp;
    temp -> next = head;
    
    len --;
}

// helper to print size of list 
void CDLL::printSize(){
    cout<< len;
}




