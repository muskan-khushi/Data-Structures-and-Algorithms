#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node (int value) {
        data = value;
        left = right = NULL;
    }
};

//Morris Traversal
//tc->O(n)
//sc-> O(1)

//inorder

//1. left part doesn't exist
//     -> note down the data
//     ->move to right

//2. left part exist
//       ->if left subtree not traverse
//              ->create the link
//              ->move to left
//       ->else (already traversed)
//            ->remove the link
//            -> note down the data
//            ->move to right

vector<int> inorder(Node* root) {
   vector<int> ans;
   while (root) {
    //left part dne
    if(root->left == NULL){
      ans.push_back(root->data);
      root = root->right;
    }
    else {
        Node* curr = root->left;
        while(curr->right && curr->right != root){
             curr = curr->right;
        }
        //left subtree not traverse
        if(curr->right == NULL){
            curr->right = root;
            root=root->left;
        }
        //left subtree traversed
        else {
            curr->right = NULL;
            ans.push_back(root->data);
            root=root->right;
        }
    }
   }
   return ans;
}


//preorder
vector<int> preorder(Node* root) {
    vector<int> ans;
    while (root) {
     //left part dne
     if(root->left == NULL){
       ans.push_back(root->data);
       root = root->right;
     }
     else {
         Node* curr = root->left;
         while(curr->right && curr->right != root){
              curr = curr->right;
         }
         //left subtree not traverse
         if(curr->right == NULL){
            ans.push_back(root->data);
             curr->right = root;
             root=root->left;
         }
         //left subtree traversed
         else {
             curr->right = NULL;
             root=root->right;
         }
     }
    }
    return ans;
 }


 //postorder
 //do NRL and reverse by morris


 //flatten binary tree to linkedlist
 //TC->O(n) and SC -> O(1)
 void flattenTree(Node* root){
      while(root){
        //left part dne
        if(root->left == NULL){
           root = root->right;
        }
        //exist
        else {
            Node* curr = root->left;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
 }
   

