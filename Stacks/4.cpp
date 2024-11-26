#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Stores the queue element
    Node* next;     // Points to the next node in the queue
};

// Queue class
class Queue {
private:
    Node* front; // Points to the front (start) of the queue
    Node* rear;  // Points to the rear (end) of the queue

public:
    Queue() {
        front = NULL; // Initially, the queue is empty
        rear = NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = value;      // Set the value
        newNode->next = NULL;       // New node will be the last, so its next is NULL

        if (rear == NULL) { // If the queue is empty
            front = rear = newNode; // Both front and rear point to the new node
        } else {
            rear->next = newNode;   // Link the new node to the current rear
            rear = newNode;         // Update rear to the new node
        }
        cout << value << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) { // If the queue is empty
            cout << "Queue underflow! Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;   // Store the current front
        front = front->next;  // Move front to the next node

        // If the queue is now empty, update rear to NULL
        if (front == NULL) {
            rear = NULL;
        }

        cout << temp->data << " removed from the queue." << endl;
        delete temp;          // Free the memory
    }

    int peek() {
        if (isEmpty()) { // If the queue is empty
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1; // Return an invalid value
        }
        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

// Main function
int main() {
    Queue queue;

    queue.enqueue(10); // Add elements
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue(); // Remove an element
    queue.dequeue();

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    queue.dequeue(); // Try removing from an empty queue

    return 0;
}

