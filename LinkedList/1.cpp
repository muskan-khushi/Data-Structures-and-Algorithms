#include <bits/stdc++.h>
using namespace std;

// Linked List stores elements in heap memory, not in contiguous memory locations
// The size of a linked list can be modified dynamically
// Each node stores the data and a pointer to the next node
// Commonly used in data structures like stacks and queues
// In real life, linked lists are used in applications like browsers (history, back/forward navigation)

// Node class definition
class Node {
public:
    int data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int val) {
        data = val; // Initialize node data
        next = nullptr; // Initialize next pointer to null
    }
};

// Function to convert an array into a linked list
Node* convertArr2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr; // If the array is empty, return null

    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* mover = head; // Pointer to move along the list

    // Loop through the array starting from the second element
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); // Create a new node with the current array element
        mover->next = temp; // Link the current node to the new node
        mover = temp; // Move the pointer to the new node
    }

    return head; // Return the head of the list
}

// Function to find the length of the linked list
// Time Complexity -> O(N)
int lengthLL(Node* head) {
    int count = 0; // Initialize count to 0
    Node* temp = head; // Temporary pointer to traverse the list
    while(temp) { // Traverse until the end of the list
        temp = temp->next; // Move to the next node
        count++; // Increment the count
    } 
    return count; // Return the length of the linked list
}

// Function to search for an element in the linked list
// Returns 1 if the element is found, otherwise 0
int checkIfPresent(Node* head, int val){
    Node* temp = head; // Temporary pointer to traverse the list
    while(temp) { // Traverse until the end of the list
        if(temp->data == val) return 1; // If the element is found, return 1
        temp = temp->next; // Move to the next node
    }
    return 0; // If the element is not found, return 0
}

// Function to display the linked list
void displayLL(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list
    while(temp) { // Traverse until the end of the list
        cout << temp->data << " -> "; // Print the data of the current node
        temp = temp->next; // Move to the next node
    }
    cout << "NULL" << endl; // Indicate the end of the list
}

int main() {
    vector<int> arr = {2, 5, 8, 7}; // Example array to convert to linked list

    // Convert the array to linked list
    Node* head = convertArr2LL(arr);

    // Display the linked list
    cout << "Linked List: ";
    displayLL(head);

    // Find and display the length of the linked list
    cout << "Length of Linked List: " << lengthLL(head) << endl;

    // Check if an element is present in the linked list
    int searchValue = 5;
    cout << "Element " << searchValue << (checkIfPresent(head, searchValue) ? " is present" : " is not present") << " in the linked list." << endl;

    // Another element check
    searchValue = 10;
    cout << "Element " << searchValue << (checkIfPresent(head, searchValue) ? " is present" : " is not present") << " in the linked list." << endl;

    return 0;
}
