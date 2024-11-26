#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = NULL; // Initially, the stack is empty
    }

    void push(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Set the value
        newNode->next = top;        // Link it to the current top
        top = newNode;              // Update top
        cout << value << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;      // Store the current top
        top = top->next;       // Move top to the next node
        cout << temp->data << " popped from stack." << endl;
        delete temp;           // Free the memory
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to peek." << endl;
            return -1; // Return an invalid value
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

// Main function
int main() {
    Stack stack;

    stack.push(10); // Push elements
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop(); // Pop an element
    stack.pop();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    stack.pop(); // Try popping from an empty stack

    return 0;
}

