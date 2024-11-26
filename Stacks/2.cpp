#include <iostream>
using namespace std;

class Queue {
private:
    int *queue;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] queue;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) { // First element being enqueued
            front = 0;
        }
        rear++;
        queue[rear] = value;
        size++;
        cout << "Enqueued: " << value << endl;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return -1;
        }
        int dequeuedValue = queue[front];
        front++;
        size--;
        if (front > rear) { // Reset the queue when it becomes empty
            front = -1;
            rear = -1;
        }
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == capacity - 1;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return queue[front];
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Attempt to enqueue in a full queue
    q.display();

    return 0;
}

