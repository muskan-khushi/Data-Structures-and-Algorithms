
//Implementation of Queue using LL

#include<bits/stdc++.h>
using namespace std;

// Class to represent each node in the queue
class QueueNode {
public:
    int val;          // Stores the value of the node
    QueueNode *next;  // Pointer to the next node in the queue

    // Constructor to initialize a new node with given data
    QueueNode(int data) {
        val = data;         // Set the value of the node
        next = nullptr;     // Initialize next to nullptr
    }
};

// Global pointers to keep track of the front and rear of the queue
QueueNode *Front = nullptr, *Rear = nullptr;

// Class to represent the queue with its basic operations
class Queue {
public:
    int size = 0;  // Tracks the current size of the queue

    // Checks if the queue is empty
    bool Empty();

    // Adds an element to the rear of the queue
    void Enqueue(int value);

    // Removes an element from the front of the queue
    void Dequeue();

    // Returns the value of the front element without removing it
    int Peek();
};

// Function to check if the queue is empty
bool Queue::Empty() {
    return Front == nullptr;  // Queue is empty if Front is nullptr
}

// Function to view the front element of the queue without removing it
int Queue::Peek() {
    if (Empty()) {  // Check if queue is empty
        cout << "Queue is Empty" << endl;
        return -1;
    } else {
        return Front->val;  // Return the value at the front
    }
}

// Function to add an element to the rear of the queue
void Queue::Enqueue(int value) {
    QueueNode *Temp = new QueueNode(value);  // Create a new node with given value

    // Check if memory allocation failed (when heap is exhausted)
    if (Temp == nullptr) {
        cout << "Queue is Full" << endl;
    } else {
        if (Front == nullptr) {  // If queue is initially empty
            Front = Temp;        // Set Front and Rear to the new node
            Rear = Temp;
        } else {                 // If queue is not empty
            Rear->next = Temp;   // Link the new node to the end of the queue
            Rear = Temp;         // Update Rear to the new node
        }
        cout << value << " Inserted into Queue " << endl;
        size++;                  // Increment size after adding the element
    }
}

// Function to remove an element from the front of the queue
void Queue::Dequeue() {
    if (Front == nullptr) {   // Check if queue is empty
        cout << "Queue is Empty" << endl;
    } else {
        cout << Front->val << " Removed From Queue" << endl;
        QueueNode *Temp = Front;   // Store current front in a temporary node
        Front = Front->next;       // Move Front to the next node
        delete Temp;               // Delete the old front node
        size--;                    // Decrement size after removing the element
    }
}

int main() {
    Queue Q;  // Create an instance of Queue

    // Add elements to the queue
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);

    // Remove an element from the queue
    Q.Dequeue();

    // Display the size of the queue
    cout << "The size of the Queue is " << Q.size << endl;

    // Display the front element of the queue
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;

    return 0;
}
