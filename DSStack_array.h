// Implement a stack based on an array.

#ifndef DSSTACK_ARRAY_H
#define DSSTACK_ARRAY_H

#include <iostream>
#include <cstring>
#include <string>

class DSStack_array 
{

private:
    int top;
    char stack[1000]; // Stack array of fixed length of 1000

public:
    DSStack_array();

    DSStack_array(const DSStack_array &);
    ~DSStack_array();
    DSStack_array &operator=(const DSStack_array &);

    int getSize();
    void push(char);
    void pop();
    char peek();
    void empty();
    bool isEmpty();
    void display();
};



#endif