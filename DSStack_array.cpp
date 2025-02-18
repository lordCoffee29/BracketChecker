#include "DSStack_array.h"

// Constructor
DSStack_array::DSStack_array() {
    top = -1; // Set top to -1 to indicate an empty stack array
}

// Copy constructor
DSStack_array::DSStack_array(const DSStack_array &stackOrig) {
    top = stackOrig.top;

    // Copy the contents into a new array 
    for(int i = 0; i < 1000; i++) {
        stack[i] = stackOrig.stack[i];
    }
}

// Destructor
DSStack_array::~DSStack_array() {

}

// Assignment operator
DSStack_array& DSStack_array::operator=(const DSStack_array &stk) {
    top = stk.top;
    strcpy(stack, stk.stack);

    return *this;
}

// Get the size of the list
int DSStack_array::getSize() {
    return (top + 1);
}

// Push an element into the top of the stack
void DSStack_array::push(char c) {
    top++; // Increment top to make the stack bigger
    stack[top] = c;
}

// Remove an element from the top of the stack
void DSStack_array::pop() {
    top--; // Decrement top to make the stack smaller
}

// Look at the element on top of the stack
char DSStack_array::peek() {
    char peekItem = stack[top];
    return peekItem;
}

// Empty the stack array
void DSStack_array::empty() {
    top = -1; // Reset the top to -1 to make the stack empty
}

// Check whether the stack is empty
bool DSStack_array::isEmpty() {
    if(top == -1) {
        return true;
    }
    else {
        return false;
    }
}

// Display the contents of the stack 
// This was mostly for testing purposes
void DSStack_array::display() {
    for(int i = 0; i <= top; i++) {
        std::cout << stack[i];
    }

    std::cout << std::endl;
}

