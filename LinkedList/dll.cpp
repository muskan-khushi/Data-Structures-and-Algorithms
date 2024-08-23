#include <bits/stdc++.h>
using namespace std;

// Node class for Doubly Linked List (DLL)
class Node
{
public:
    int data;      // Data stored in the node
    Node *next;    // Pointer to the next node
    Node *back;    // Pointer to the previous node

    // Constructor to initialize a node with data, next, and back pointers
    Node(int data1, Node *next1 = nullptr, Node *back1 = nullptr)
    {
        data = data1;       // Assign data to the node
        next = next1;       // Assign next pointer
        back = back1;       // Assign back pointer
    }
};

// Function to convert an array into a doubly linked list (DLL)
Node* convertArr2DLL(vector<int> &arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head;  // Pointer to track the last node added

    // Loop through the array and create the DLL
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with the current element and link it to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;  // Move the pointer to the new node
    }
    return head;  // Return the head of the DLL
}

// Function to print the DLL from head to tail
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;  // Move to the next node
    }
    cout << endl;
}

// Function to delete the head node of the DLL
Node* deleteHead(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;  // If the list is empty or has only one node, return NULL
    }

    Node* prev = head;  // Store the current head
    head = head->next;  // Move head to the next node
    head->back = nullptr;  // Set the back pointer of the new head to NULL
    prev->next = nullptr;  // Set the next pointer of the old head to NULL

    delete prev;  // Delete the old head
    return head;  // Return the new head
}

// Function to delete the tail node of the DLL
Node* deleteTail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;  // If the list is empty or has only one node, return NULL
    }

    Node* tail = head;
    // Traverse to the last node
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* newTail = tail->back;  // Get the previous node of the tail
    newTail->next = nullptr;  // Set the next pointer of the new tail to NULL
    tail->back = nullptr;  // Set the back pointer of the old tail to NULL

    delete tail;  // Delete the old tail
    return head;  // Return the head
}

// Function to delete the Kth node in the DLL
Node* deleteK(Node* head, int k) {
    if (head == NULL) {
        return NULL;  // If the list is empty, return NULL
    }

    int cnt = 0;
    Node* kNode = head;

    // Traverse to the Kth node
    while (kNode != NULL) {
        cnt++;
        if (cnt == k) break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if (prev == NULL && front == NULL) {
        // If it's the only node in the list
        return NULL;
    }
    else if (prev == NULL) {
        // If Kth node is the head
        return deleteHead(head);
    }
    else if (front == NULL) {
        // If Kth node is the tail
        return deleteTail(head);
    }

    // If Kth node is in the middle
    prev->next = front;
    front->back = prev;

    kNode->next = NULL;
    kNode->back = NULL;

    delete kNode;  // Delete the Kth node
    return head;
}

// Function to delete a given node in the DLL (cannot delete the head)
void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    if (front == NULL) {
        // If the node is the tail
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    // If the node is in the middle
    prev->next = front;
    front->back = prev;

    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;  // Delete the node
}

// Function to insert a node before the head of the DLL
Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;  // Return the new head
}

// Function to insert a node before the tail of the DLL
Node* insertBeforeTail(Node* head, int val) {
    if (head->next == NULL) {
        return insertBeforeHead(head, val);  // If there's only one node, treat it as inserting before the head
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;

    return head;  // Return the head
}

// Function to insert a node before a given node
void insertBeforeNode(Node* node, int val) {
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

// Function to insert a node before the Kth element in the DLL
Node* insertBeforeKthElement(Node* head, int k, int val) {
    if (k == 1) {
        return insertBeforeHead(head, val);  // If K is 1, insert before the head
    }

    Node* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;  // Return the head
}

int main() {
    vector<int> arr = {12, 5, 8, 7};  // Example array to convert to DLL

    // Convert the array to DLL and reset before each operation
    Node* head;

    // Operation 1: Delete the head of the DLL
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = deleteHead(head);
    cout << "After deleting head: ";
    print(head);

    // Operation 2: Delete the tail of the DLL
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = deleteTail(head);
    cout << "After deleting tail: ";
    print(head);

    // Operation 3: Delete the 2nd node of the DLL
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = deleteK(head, 2);
    cout << "After deleting 2nd node: ";
    print(head);

    // Operation 4: Insert before head
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = insertBeforeHead(head, 20);
    cout << "After inserting 20 before head: ";
    print(head);

    // Operation 5: Insert before tail
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = insertBeforeTail(head, 15);
    cout << "After inserting 15 before tail: ";
    print(head);

    // Operation 6: Insert before the 2nd element
    head = convertArr2DLL(arr);
    cout << "Original DLL: ";
    print(head);
    head = insertBeforeKthElement(head, 2, 25);
    cout << "After inserting 25 before 2nd element: ";
    print(head);

    return 0;
}
