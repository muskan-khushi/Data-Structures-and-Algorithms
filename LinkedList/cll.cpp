#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    // Constructor to create a node
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Insert at the beginning
void insertAtHead(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        // Empty list
        newNode->next = newNode;
        head = newNode;
        return;
    }

    // Non-empty list
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    newNode->next = head;
    temp->next = newNode;
    head = newNode; // Update head
}

// Insert at the end
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        // Empty list
        newNode->next = newNode;
        head = newNode;
        return;
    }

    // Non-empty list
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    temp->next = newNode;
    newNode->next = head;
}

// Delete the head node
void deleteHead(Node*& head) {
    if (!head) return; // Empty list

    if (head->next == head) {
        // Single node
        delete head;
        head = NULL;
        return;
    }

    // Multiple nodes
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next; // Find the last node
    }
    Node* toDelete = head;
    temp->next = head->next; // Link last node to second node
    head = head->next;       // Update head
    delete toDelete;
}

// Delete a node at a specific position
void deleteAtPosition(Node*& head, int k) {
    if (!head) return; // Empty list

    if (k == 1) {
        deleteHead(head); // Use the deleteHead logic
        return;
    }

    // Traverse to the (k-1)th node
    Node* temp = head;
    int count = 1;
    while (count < k - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Delete the k-th node
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// Display the list
void display(Node* head) {
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

int main() {
    Node* head = NULL;

    // Test the insertion
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    display(head); // Output: 20 -> 10 -> 30 -> (head)

    // Test deletion
    deleteAtPosition(head, 1); // Delete head
    display(head); // Output: 10 -> 30 -> (head)
    deleteAtPosition(head, 2); // Delete tail
    display(head); // Output: 10 -> (head)

    return 0;
}

