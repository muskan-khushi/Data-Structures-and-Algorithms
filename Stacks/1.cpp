#include<bits/stdc++.h>
using namespace std;

// Implementation of Stack using Arrays
class Stack {
  int size;   // Maximum size of the stack
  int *arr;   // Dynamic array to store stack elements
  int top;    // Variable to keep track of the top element's index

public:
    // Constructor to initialize stack with a default size of 1000
    Stack() {
      top = -1;            // Initially, the stack is empty, so top is set to -1
      size = 1000;         // Default maximum size of the stack
      arr = new int[size]; // Allocate memory for stack elements
    }

    // Function to push (add) an element to the top of the stack
    void push(int x) {
      // Move the 'top' pointer up and add the new element at the new top position
      top++;
      arr[top] = x;   // Insert the element at the top index
    }

    // Function to pop (remove) the top element from the stack
    int pop() {
      int x = arr[top]; // Get the top element to return later
      top--;            // Move the 'top' pointer down to remove the element
      return x;         // Return the removed element
    }

    // Function to get the top element of the stack without removing it
    int Top() {
      return arr[top];  // Return the element at the current 'top' position
    }

    // Function to get the current size of the stack
    int Size() {
      return top + 1;   // 'top' is index-based, so size is top + 1
    }
};

int main() {
  // Creating a Stack object 's' with default size
  Stack s;

  // Push elements onto the stack
  s.push(6);
  s.push(3);
  s.push(7);

  // Display the top element and size before deleting any element
  cout << "Top of stack before deleting any element: " << s.Top() << endl;
  cout << "Size of stack before deleting any element: " << s.Size() << endl;

  // Pop (delete) the top element from the stack
  cout << "The element deleted is: " << s.pop() << endl;

  // Display the top element and size after deleting an element
  cout << "Size of stack after deleting an element: " << s.Size() << endl;
  cout << "Top of stack after deleting an element: " << s.Top() << endl;

  return 0;
}
