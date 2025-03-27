#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node *left, *right;

      Node(int value){
        left=right=NULL;
        data = value;
      }
};

//level order traversal
//tc->O(n) sc->O(n)
vector<int> levelOrder(Node *root){
    queue<Node*> q;
    q.push(root);

    vector<int> ans;
    Node* temp;

    while (!q.empty()){
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if (temp->right){
            q.push(temp->right);
        }
    }
    return ans;

}

//size of binary tree
//method 1
class Solution1 {
    public:
      void Total(Node* root, int &count){
          if (root == NULL) return;
          
          count++;
          Total(root->left, count);
          Total(root->right, count);
      }
    
      int getSize(Node* root) {
          int count = 0;
          Total(root, count);
          return count;
      }
  };

  //method 2
  class Solution2 {
    public:
     
      int getSize(Node* root) {
        if (root == NULL) return 0;
        return 1 + getSize(root->left)+getSize(root->right);
      }
  };

 //Sum of a Binary Tree
 //method 1
 class Solution3 {
    public:
      void sumi(Node* root, int &sum){
          if (root == NULL) return;
          
          sum += root->data;
          sumi(root->left, sum);
          sumi(root->right, sum);
      }
      
      int sumBT(Node* root) {
          int sum = 0;
          sumi(root, sum);
          return sum;
      }
  };

  //method 2
  class Solution4 {
    public:
      int sumBT(Node* root) {
          // code here
          if (root == NULL) return 0;
          int sum = root->data + sumBT(root->left) + sumBT(root->right);
          return sum;
      }
  };


  //count leaf nodes
  //method 1
  class Solution5 {
    public:
      void counti(Node* root, int &count){
          if (root == NULL) return;
          
          if (!root->left || !root->right){
              count++;
          }
          
          counti(root->left, count);
          counti(root->right, count);
      }
      // Function to count the number of leaf nodes in a binary tree.
      int countLeaves(Node* root) {
          // write code here
          int count = 0;
          counti(root, count);
          return count;
      }
  };

  //method 2
  class Solution6 {
    public:
      int countLeaves(Node* root) {
          // write code here
          if (root == NULL) return 0;
          if(!root->left && !root->right){
              return 1;
          }
          
          return(countLeaves(root->left) + countLeaves(root->right));
      }
  };

  //Count Non leaf Nodes
  //method 1
  class Solution7 {
    public:
      void counti(Node* root, int &count){
          if (root == NULL) return;
          
          // Check if it's a non-leaf node (has at least one child)
          if (root->left || root->right) {
              count++;
          }
          
          counti(root->left, count);
          counti(root->right, count);
      }
  
      int countNonLeafNodes(Node* root) {
          int count = 0;
          counti(root, count);
          return count;
      }
  };

  //method 2
  class Solution8 {
    public:
      int countNonLeafNodes(Node* root) {
          // Handle empty tree
          if (root == NULL) return 0;
  
          // If the node is a leaf node, return 0
          if (!root->left && !root->right) return 0;
  
          // Otherwise, it is a non-leaf node. Count it and proceed recursively.
          return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
      }
  };

  //height of binary tree
  int height(Node* root) {
    if (root == NULL) return 0;
    
    if(!root->left && !root->right) return 1;

    return (1 + max(height(root->left), height(root->right)));
  }



  
  
  