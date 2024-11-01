#include<bits/stdc++.h>
using namespace std;

// Queue class to implement a queue using an array
class Queue {
  int *arr;      // Array to store elements in the queue
  int start;     // Points to the front of the queue
  int end;       // Points to the rear of the queue
  int currSize;  // Tracks the current number of elements in the queue
  int maxSize;   // Defines the maximum capacity of the queue

public:
    // Default constructor with initial size 16
    Queue() {
      arr = new int[16];   // Allocate space for 16 elements by default
      start = -1;          // Initialize 'start' to -1 indicating an empty queue
      end = -1;            // Initialize 'end' to -1 indicating an empty queue
      currSize = 0;        // Initial queue size is 0
    }

    // Parameterized constructor to set the maximum size of the queue
    Queue(int maxSize) {
      this->maxSize = maxSize;  // Set the maximum size of the queue
      arr = new int[maxSize];   // Allocate array memory based on given max size
      start = -1;               // Initialize start for empty queue
      end = -1;                 // Initialize end for empty queue
      currSize = 0;             // Initial size is 0 since no elements are added
    }
  
    // Function to add an element to the queue
    void push(int newElement) {
      // Check if queue is full
      if (currSize == maxSize) {  
        cout << "Queue is full\nExiting..." << endl;
        exit(1);  // Exit if queue has reached maximum capacity
      }
      // If queue is empty, initialize start and end pointers
      if (end == -1) {  
        start = 0;   // Set start to 0 as we begin adding elements
        end = 0;
      } else
        // Otherwise, increment end pointer in a circular fashion
        end = (end + 1) % maxSize;
      
      // Insert the new element at 'end' position
      arr[end] = newElement;
      cout << "The element pushed is " << newElement << endl;
      
      // Increment the current size after adding an element
      currSize++; 
    }

    // Function to remove an element from the front of the queue
    int pop() {
      // Check if the queue is empty
      if (start == -1) {
        cout << "Queue Empty\nExiting..." << endl;
        exit(1);  // Exit if no elements to remove
      }
      // Retrieve the element at the front
      int popped = arr[start]; 
      
      // If this was the only element in the queue, reset pointers to empty
      if (currSize == 1) {
        start = -1;
        end = -1;
      } else
        // Move start pointer forward in a circular fashion
        start = (start + 1) % maxSize;
      
      // Decrease the current size as an element is removed
      currSize--;
      return popped;  // Return the removed element
    }

    // Function to return the front element without removing it
    int top() {
      // Check if the queue is empty
      if (start == -1) {
        cout << "Queue is Empty" << endl;
        exit(1);  // Exit if there are no elements in the queue
      }
      return arr[start];  // Return the element at the front of the queue
    }

    // Function to return the current size of the queue
    int size() {
      return currSize;  // Return the number of elements in the queue
    }
};

// Main function to demonstrate queue operations
int main() {
  Queue q(6);  // Create a Queue object with a maximum size of 6

  // Add elements to the queue
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  
  // Show the front element and current size before deletion
  cout << "The peek of the queue before deleting any element: " << q.top() << endl;
  cout << "The size of the queue before deletion: " << q.size() << endl;
  
  // Remove an element from the front of the queue
  cout << "The first element to be deleted: " << q.pop() << endl;
  
  // Show the front element and current size after deletion
  cout << "The peek of the queue after deleting an element: " << q.top() << endl;
  cout << "The size of the queue after deleting an element: " << q.size() << endl;

  return 0;
}
