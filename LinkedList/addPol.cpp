#include <bits/stdc++.h>
using namespace std;

// Node class represents a single term in the polynomial
class Node {
    public:
        int coeff; // Coefficient of the term
        int pow;   // Power (exponent) of the term
        Node* next; // Pointer to the next term in the polynomial

        // Constructor to initialize a node
        Node(int c, int p) {
            coeff = c;
            pow = p;
            next = nullptr; // Initialize the next pointer as null
        }
};

// Function to add two polynomials represented as linked lists
Node* addPolynomial(Node* head1, Node* head2) {
    // Dummy node acts as the start of the resulting polynomial
    Node* dummy = new Node(0, 0);
    Node* prev = dummy; // Pointer to track the last node in the result list

    // Pointers to traverse the two input polynomial linked lists
    Node* curr1 = head1;
    Node* curr2 = head2;

    // Loop until we traverse both linked lists completely
    while (curr1 != nullptr && curr2 != nullptr) {
        // Case 1: If the power of the second polynomial term is larger
        if (curr1->pow < curr2->pow) {
            prev->next = curr2; // Add the term from the second polynomial
            prev = curr2;       // Move the result pointer forward
            curr2 = curr2->next; // Move to the next term in the second polynomial
        }
        // Case 2: If the power of the first polynomial term is larger
        else if (curr1->pow > curr2->pow) {
            prev->next = curr1; // Add the term from the first polynomial
            prev = curr1;       // Move the result pointer forward
            curr1 = curr1->next; // Move to the next term in the first polynomial
        }
        // Case 3: If the powers of both terms are equal
        else {
            curr1->coeff += curr2->coeff; // Add the coefficients of both terms
            prev->next = curr1; // Add the updated term to the result list
            prev = curr1;       // Move the result pointer forward
            curr1 = curr1->next; // Move to the next term in the first polynomial
            curr2 = curr2->next; // Move to the next term in the second polynomial
        }
    }

    // Append any remaining terms from the first polynomial
    if (curr1 != nullptr) {
        prev->next = curr1;
    }

    // Append any remaining terms from the second polynomial
    if (curr2 != nullptr) {
        prev->next = curr2;
    }

    return dummy->next; // Return the merged polynomial, skipping the dummy node
}

// Function to print the polynomial as a linked list
void printList(Node* head) {
    Node* curr = head; // Start from the head of the list

    // Traverse the linked list and print each term
    while (curr != nullptr) {
        cout << curr->coeff << "," << curr->pow << " "; // Print coefficient and power
        curr = curr->next; // Move to the next term
    }

    cout << endl; // End the output with a newline
}

int main() {
    // First polynomial: 5x^2 + 4x^1 + 2x^0
    Node* head1 = new Node(5, 2); 
    head1->next = new Node(4, 1);
    head1->next->next = new Node(2, 0);

    // Second polynomial: -5x^1 - 5x^0
    Node* head2 = new Node(-5, 1); 
    head2->next = new Node(-5, 0);

    // Add the two polynomials and store the result
    Node* head = addPolynomial(head1, head2);

    // Print the resulting polynomial
    cout << "Resultant Polynomial: ";
    printList(head);

    return 0;
}
