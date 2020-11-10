#ifndef __CDLL_H__
#define __CDLL_H__

#ifndef NULL
#define NULL 0x00
#endif


#include <string>
#include <vector>

// define node class
class node {
    private:
        int x;
        node * next;
        node * prev;
    public:
        node(int x);
        ~node();
    friend class CDLL;
};

// define circular doubly linked list class
class CDLL {
    private: 
        node * head;
        node * current;
        int len;
    public:
        CDLL();
        ~CDLL();

        // define methods 
        void prepend(int x);
        void append(int x);
        void getFirst();
        void next();
        void previous();
        void printCurrent();
        void printAll();
        void printSize();
        void removeLast();
};

#endif
