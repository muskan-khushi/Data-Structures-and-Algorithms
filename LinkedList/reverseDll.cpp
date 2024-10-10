#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class for Doubly Linked List (DLL)
class Node {
public:
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node
    Node *prev;     // Pointer to the previous node

    // Default constructor
    Node() {
        this->data = 0;  // Initialize data to 0
        next = NULL;     // Initialize next pointer to NULL
        prev = NULL;     // Initialize prev pointer to NULL
    }

    // Constructor to initialize a node with data
    Node(int data) {
        this->data = data;  // Assign data to the node
        this->next = NULL;  // Initialize next pointer to NULL
        this->prev = NULL;  // Initialize prev pointer to NULL
    }

    // Constructor to initialize a node with data, next, and prev pointers
    Node(int data, Node* next, Node* prev) {
        this->data = data;   // Assign data to the node
        this->next = next;   // Assign the next pointer
        this->prev = prev;   // Assign the prev pointer
    }
};

// Function to reverse a Doubly Linked List (DLL)
// Takes the head of the DLL as input and returns the new head after reversing
Node* reverseDLL(Node* head) {   
    // If the list is empty or has only one node, return the head as is
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;     // Initialize a pointer to track the previous node
    Node* current = head;  // Start with the current node as the head

    /*
    Logic:
    - The reversal process involves swapping the 'next' and 'prev' pointers for each node.
    - This effectively reverses the direction of the list.
    - We'll traverse the list using the 'current' pointer. As we progress:
      - 'current->prev' should now point to what was originally 'current->next'.
      - 'current->next' should point to what was originally 'current->prev'.
    - We continue this process until we reach the end of the list.
    */

    while (current != NULL) { 
        prev = current->prev;            // Save the current's prev pointer
        current->prev = current->next;   // Swap the prev and next pointers
        current->next = prev;            // Continue the swap process

        // Move to the next node in the original list (which is the previous node in the reversed list)
        current = current->prev;
    }

    /*
    After the loop:
    - 'prev' will be pointing to the node that was the original tail of the list.
    - Since the last operation of the loop makes 'current' NULL, 'prev' holds the new head of the reversed list.
    - But 'prev' itself is pointing to the node that was previously 'current', so we return 'prev->prev' which is now the new head.
    */
    return prev->prev;
}

int main() {
    // Example usage (uncomment to use):
    /*
    Node* head = new Node(1);   // Creating the first node
    head->next = new Node(2);   // Creating the second node
    head->next->prev = head;    // Linking the second node back to the first
    head->next->next = new Node(3); // Creating the third node
    head->next->next->prev = head->next; // Linking the third node back to the second

    cout << "Original DLL: ";
    Node* temp = head;
    while (temp != NULL) {  // Printing the original DLL
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = reverseDLL(head);  // Reversing the DLL

    cout << "Reversed DLL: ";
    temp = head;
    while (temp != NULL) {  // Printing the reversed DLL
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    */

    return 0;
}

//TC -> O(N), SC -> O(1)