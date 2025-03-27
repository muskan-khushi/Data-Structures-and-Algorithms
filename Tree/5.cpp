#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = NULL;
    }
};

//left view of binary tree
//tc-> O(n) //SC -> O(n)

//method 1 - with queue
vector<int> leftView1(Node* root){
    queue<Node*> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            Node* temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }

    return ans;
}

//method 2 - with recursion
class Solution {
    public:
      void lView(Node* root, int level, vector<int>& ans){
          if (root == NULL) return;
          
          if(level == ans.size()) ans.push_back(root->data);
          lView(root->left, level+1, ans);
          lView(root->right, level+1, ans);
      }
    
      vector<int> leftView(Node *root) {
          vector<int> ans;
          lView(root, 0, ans);
          return ans;
      }
  };


//Right View of Binary Tree
//method 1 - using queue
vector<int> rightView1(Node* root){
    queue<Node*> q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()){
        int n = q.size();
        ans.push_back(q.front()->data);
        while(n--){
            Node* temp;
            q.front();
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
    }
    return ans;
}

//method 2: using recursion
//method 2 - with recursion
class Solution
{
    public:
    
    void rView(Node* root, int level, vector<int>& ans){
        if (root == NULL) return;
        
        if (level == ans.size()) ans.push_back(root->data);
        rView(root->right, level+1, ans);
        rView(root->left, level+1, ans);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       rView(root, 0, ans);
       return ans;
    }
};