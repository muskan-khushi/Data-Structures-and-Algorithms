#include <bits/stdc++.h>
using namespace std;

//create binary tree 
//depth wise

//if x == -1, return null
//create node
//left side jao
//right side jao
//node address return

class Node {
    public:
      int data;
      Node *left, *right;

      Node(int value){
        left=right=NULL;
        data = value;
      }
};

//TC -> O(n)
//SC -> O(n)
Node* BinaryTree(){
    int x;
    cin>>x;
    if(x==-1) return NULL;

    Node *temp = new Node(x);
    //left side create
    cout << "Enter the left child of "<<x<<": ";
    temp->left = BinaryTree();
    //right side create
    cout << "Enter the right child of "<<x<<": ";
    temp->right = BinaryTree();
    return temp;
}

//Tree Traversals

//              1     
//          2       7
//      3       6        8
// 4       5          9    10
//(6 has no child, is child of 2 not 7)

//PreOrder (NLR) -> 1 2 3 4 5 6 7 8 9 10
//Inorder (LNR) -> 4 3 5 2 6 1 7 9 8 10
//PostOrder (LRN) -> 4 5 3 6 2 9 10 8 7 1

//TC -> O(n)

void PreOrder(Node* root){
    if (root == NULL) return;
    
    //Node
    cout << root->data;
    //left
    PreOrder(root->left);
    //right
    PreOrder(root->right);
}

void InOrder(Node* root){
    if (root == NULL) return;

    //left
    InOrder(root->left);
    //node
    cout << root->data;
    //right
    InOrder(root->right);
}

void PostOrder(Node* root){
    if (root == NULL) return;
    
    //left
    PostOrder(root->left);
    //right
    PostOrder(root->right);
    //Node
    cout << root->data;
}

int main(){

    //Tree Creation
    cout << "Enter the root node: ";
    Node* root;
    root = BinaryTree();

    //PreOrder Print
    cout << "Pre Order: ";
    PreOrder(root);
    //Inorder Print
    cout << "In Order: ";
    InOrder(root);
    //PostOrder Print
    cout << "Post Order: ";
    PostOrder(root);
}