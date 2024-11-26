#include <iostream>
#include <queue> // For Level Order Traversal
using namespace std;

// Definition of a Node in the binary tree
class Node {
public:
    int data;      // Data stored in the node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

    // Constructor to initialize a node with given data
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the binary tree recursively
Node* buildTree(Node* root) {
    cout << "Enter data (-1 for no node): ";
    int data;
    cin >> data;

    // Base case: If the user enters -1, it means no node should be created here
    if (data == -1) return NULL;

    // Create a new node with the input data
    root = new Node(data);

    // Recursively build the left subtree
    cout << "Enter data for the left child of " << data << ": " << endl;
    root->left = buildTree(root->left);

    // Recursively build the right subtree
    cout << "Enter data for the right child of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root; // Return the created node
}

// Function for Inorder Traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;        // Base case: If the node is NULL, return
    inorder(root->left);             // Traverse the left subtree
    cout << root->data << " ";       // Visit the root node
    inorder(root->right);            // Traverse the right subtree
}

// Function for Preorder Traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) return;        // Base case: If the node is NULL, return
    cout << root->data << " ";       // Visit the root node
    preorder(root->left);            // Traverse the left subtree
    preorder(root->right);           // Traverse the right subtree
}

// Function for Postorder Traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) return;        // Base case: If the node is NULL, return
    postorder(root->left);           // Traverse the left subtree
    postorder(root->right);          // Traverse the right subtree
    cout << root->data << " ";       // Visit the root node
}

// Function for Level Order Traversal (Row by Row)
void levelOrder(Node* root) {
    if (root == NULL) return;        // Base case: If the tree is empty, return

    queue<Node*> q;                  // Queue to keep track of nodes to visit
    q.push(root);                    // Start with the root node

    while (!q.empty()) {             // While there are nodes to process
        Node* current = q.front();   // Get the front node from the queue
        q.pop();                     // Remove it from the queue
        cout << current->data << " "; // Visit the current node

        if (current->left)           // If the left child exists, add it to the queue
            q.push(current->left);
        if (current->right)          // If the right child exists, add it to the queue
            q.push(current->right);
    }
}

int main() {
    Node* root = NULL; // Initialize the root of the binary tree

    // Build the binary tree
    root = buildTree(root);

    // Display all traversals
    cout << "\nInorder Traversal (Left, Root, Right): ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal (Root, Left, Right): ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal (Left, Right, Root): ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal (Row by Row): ";
    levelOrder(root);
    cout << endl;

    return 0;
}


