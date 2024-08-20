#include <bits/stdc++.h>
using namespace std;

// Linked List stores elements in heap memory, not in contiguous memory locations.
// The size of a linked list can be modified dynamically.
// Each node stores the data and a pointer to the next node.
// Commonly used in data structures like stacks and queues.
// In real life, linked lists are used in applications like browsers (history, back/forward navigation).

// Node class definition
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int val) {
        data = val;           // Initialize node data
        next = nullptr;       // Initialize next pointer to null
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
        mover->next = temp;            // Link the current node to the new node
        mover = temp;                  // Move the pointer to the new node
    }

    return head; // Return the head of the list
}

// Function to find the length of the linked list
// Time Complexity -> O(N)
int lengthLL(Node* head) {
    int count = 0;       // Initialize count to 0
    Node* temp = head;   // Temporary pointer to traverse the list
    while(temp) {        // Traverse until the end of the list
        temp = temp->next; // Move to the next node
        count++;           // Increment the count
    } 
    return count;        // Return the length of the linked list
}

// Function to search for an element in the linked list
// Returns 1 if the element is found, otherwise 0
int checkIfPresent(Node* head, int val){
    Node* temp = head; // Temporary pointer to traverse the list
    while(temp) {      // Traverse until the end of the list
        if(temp->data == val) return 1; // If the element is found, return 1
        temp = temp->next;              // Move to the next node
    }
    return 0; // If the element is not found, return 0
}

// Function to display the linked list
void displayLL(Node* head) {
    Node* temp = head; // Temporary pointer to traverse the list
    while(temp) {      // Traverse until the end of the list
        cout << temp->data << " -> "; // Print the data of the current node
        temp = temp->next;            // Move to the next node
    }
    cout << "NULL" << endl; // Indicate the end of the list
}

// Function to print the linked list in a simplified format
void print(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Deletion of the head of the linked list
Node* removeHead(Node* head){
    if(head == NULL) return head; // If the list is empty, return null
    Node* temp = head;
    head = head->next;            // Move the head to the next node
    delete temp;                  // Delete the old head
    return head;
}

// Deletion of the tail of the linked list
Node* removeTail(Node* head){
    if (head == NULL || head->next == NULL)
        return NULL; // If the list is empty or has one node, return null

    Node* temp = head;
    while (temp->next->next != NULL){ // Traverse to the second last node
        temp = temp->next;
    }
    delete temp->next;    // Delete the last node
    temp->next = nullptr; // Set the new last node's next to null

    return head;
}

// Deleting the Kth element of the linked list
Node* removeK(Node* head, int k){
    if (head == NULL) return head; // If the list is empty, return null

    if (k == 1){ // Special case for deleting the head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 1;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL){
        if (cnt == k){ // If the current node is the Kth node
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}

// Deleting an element by its value
Node* removeElement(Node* head, int el){
    if (head == NULL) return head; // If the list is empty, return null

    if (head->data == el){ // Special case for deleting the head
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL){
        if (temp->data == el){ // If the current node has the target value
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Function to insert a node at the head of the linked list
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val); // Create a new node
    newNode->next = head;          // Point the new node to the old head
    return newNode;                // Return the new head
}

// Function to insert a node at the tail of the linked list
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val); // Create a new node
    if (head == NULL) return newNode; // If the list is empty, return the new node as head

    Node* temp = head;
    while (temp->next) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the last node to the new node
    return head;
}

// Function to insert a node at the Kth position in the linked list
Node* insertAtK(Node* head, int k, int val) {
    if (k == 1) return insertAtHead(head, val); // Special case for inserting at the head

    Node* newNode = new Node(val); // Create a new node
    Node* temp = head;

    for (int i = 1; i < k - 1; i++) {
        if (temp == NULL) break; // If K is out of bounds, break
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) { // If K is out of bounds
        cout << "Position out of bounds. Inserting at the end instead." << endl;
        return insertAtTail(head, val); // Insert at the end
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to insert a node after the first occurrence of a specific value
Node* insertAfterElement(Node* head, int el, int val) {
    Node* temp = head;

    while (temp && temp->data != el) { // Traverse to find the node with the given value
        temp = temp->next;
    }

    if (temp) { // If the node with the given value is found
        Node* newNode = new Node(val); // Create a new node
        newNode->next = temp->next; // Link the new node to the next node
        temp->next = newNode; // Link the found node to the new node
    } else {
        cout << "Element not found. Inserting at the end instead." << endl;
        return insertAtTail(head, val); // Insert at the end
    }

    return head;
}

int main() {
    // Initial linked list from array {2, 5, 8, 7}
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);

    // Display the original linked list.
    cout << "Original Linked List: ";
    displayLL(head);

    // Test case 1: Insert at the head.
    head = insertAtHead(head, 1); // Expected: 1 -> 2 -> 5 -> 8 -> 7 -> NULL
    cout << "After inserting 1 at the head: ";
    displayLL(head);

    // Test case 2: Insert at the tail.
    head = insertAtTail(head, 10); // Expected: 1 -> 2 -> 5 -> 8 -> 7 -> 10 -> NULL
    cout << "After inserting 10 at the tail: ";
    displayLL(head);

    // Test case 3: Insert at the 4th position.
    head = insertAtK(head, 4, 6); // Expected: 1 -> 2 -> 5 -> 6 -> 8 -> 7 -> 10 -> NULL
    cout << "After inserting 6 at position 4: ";
    displayLL(head);

    // Test case 4: Insert after the first occurrence of 5.
    head = insertAfterElement(head, 5, 9); // Expected: 1 -> 2 -> 5 -> 9 -> 6 -> 8 -> 7 -> 10 -> NULL
    cout << "After inserting 9 after 5: ";
    displayLL(head);

    // Test case 5: Verify the final structure of the linked list
    cout << "Final Linked List structure: ";
    displayLL(head);

    // Test case 6: Attempt to insert at a position greater than the length of the list.
    head = insertAtK(head, 20, 12); // Expected: Insertion at the tail since position is out of bounds.
    cout << "After attempting to insert 12 at position 20: ";
    displayLL(head);

    // Test case 7: Delete the head of the linked list.
    head = removeHead(head); // Expected: 2 -> 5 -> 9 -> 6 -> 8 -> 7 -> 10 -> 12 -> NULL
    cout << "After deleting the head: ";
    displayLL(head);

    // Test case 8: Delete the tail of the linked list.
    head = removeTail(head); // Expected: 2 -> 5 -> 9 -> 6 -> 8 -> 7 -> 10 -> NULL
    cout << "After deleting the tail: ";
    displayLL(head);

    // Test case 9: Delete the 3rd element of the linked list.
    head = removeK(head, 3); // Expected: 2 -> 5 -> 6 -> 8 -> 7 -> 10 -> NULL
    cout << "After deleting the 3rd element: ";
    displayLL(head);

    // Test case 10: Delete an element by its value.
    head = removeElement(head, 8); // Expected: 2 -> 5 -> 6 -> 7 -> 10 -> NULL
    cout << "After deleting the element with value 8: ";
    displayLL(head);

    return 0;
}

