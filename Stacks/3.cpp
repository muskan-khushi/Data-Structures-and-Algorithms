//Implementation of Stack using LL

#include<iostream>
using namespace std;

// Structure for each node in the stack
struct stackNode {
    int data;          // Data value of the node
    stackNode *next;   // Pointer to the next node in the stack

    // Constructor to initialize a new node with the given data
    stackNode(int d) {
        data = d;        // Set the data of the node
        next = NULL;     // Initially, next is NULL since it has no link
    }
};

// Stack structure implemented using linked list
struct stack {
    stackNode *top;  // Pointer to the top node of the stack
    int size;        // Variable to keep track of the stack's current size

    // Constructor to initialize an empty stack
    stack() {
        top = NULL;    // Stack is empty, so top is set to NULL
        size = 0;      // Initial size is 0
    }

    // Function to push (add) an element to the top of the stack
    void stackPush(int x) {
        stackNode *element = new stackNode(x); // Create a new node with given data
        element->next = top;                   // Link new node to current top
        top = element;                         // Update top to the new node
        cout << "Element pushed\n";
        size++;                                // Increment stack size
    }

    // Function to pop (remove) the top element from the stack
    int stackPop() {
        if (top == NULL) {   // Check if the stack is empty
            return -1;       // Return -1 to indicate no element to pop
        }
        int topData = top->data; // Retrieve the data from the top node
        stackNode *temp = top;   // Store the current top in a temporary node
        top = top->next;         // Move top pointer to the next node
        delete temp;             // Delete the old top node
        size--;                  // Decrease stack size
        return topData;          // Return the popped data
    }

    // Function to get the current size of the stack
    int stackSize() {
        return size;             // Return the current size of the stack
    }

    // Function to check if the stack is empty
    bool stackIsEmpty() {
        return top == NULL;      // If top is NULL, stack is empty
    }

    // Function to get the top element of the stack without removing it
    int stackPeek() {
        if (top == NULL)         // Check if stack is empty
            return -1;           // Return -1 if no element at top
        return top->data;        // Return the data of the top node
    }

    // Function to print all elements of the stack
    void printStack() {
        stackNode *current = top;   // Start from the top of the stack
        while (current != NULL) {   // Iterate till the end of the stack
            cout << current->data << " ";  // Print the data of the current node
            current = current->next;       // Move to the next node
        }
        cout << "\n";
    }
};

int main() {
    stack s;

    // Push an element onto the stack
    s.stackPush(10);

    // Pop an element and display it
    cout << "Element popped: " << s.stackPop() << "\n";

    // Display the current size of the stack
    cout << "Stack size: " << s.stackSize() << "\n";

    // Check if the stack is empty
    cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";

    // Peek at the top element of the stack without removing it
    cout << "Stack's top element: " << s.stackPeek() << "\n";

    // Print all elements of the stack
    cout << "Current Stack: ";
    s.printStack();

    return 0;
}
