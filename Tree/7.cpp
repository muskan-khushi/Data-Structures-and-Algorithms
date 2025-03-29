#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
      data = value;
      left = right = NULL;
    }
};

// pre and in -> tree construction possible
//post and in -> possible
//pre and post -> not possible
//[only lif no duplicate elements present]

//eg: in - 4,2,8,5,9,1,6,3,7,10
//    pre - 1,2,4,5,8,9,3,6,7,10
// construct the tree


//Construct binary tree from preorder and inorder
//tc-> O(n2) //sc -> O(n)
// Find target element in inorder array
int find(int* in, int target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == target) return i;
    }
    return -1;
}


// Construct tree from Inorder & Preorder
Node* buildFromPre(int* in, int* pre, int InStart, int InEnd, int &index) {
  if (InStart > InEnd) return NULL;

  Node* root = new Node(pre[index]);
  int pos = find(in, pre[index], InStart, InEnd);
  index++; // Move to next preorder element

  root->left = buildFromPre(in, pre, InStart, pos - 1, index);
  root->right = buildFromPre(in, pre, pos + 1, InEnd, index);

  return root;
}

// Construct tree from Inorder & Postorder
Node* buildFromPost(int* in, int* post, int InStart, int InEnd, int &index) {
  if (InStart > InEnd) return NULL;

  Node* root = new Node(post[index--]);  // Take element and decrement index
  int pos = find(in, root->data, InStart, InEnd);

  // **Right subtree is built first in postorder**
  root->right = buildFromPost(in, post, pos + 1, InEnd, index);
  root->left = buildFromPost(in, post, InStart, pos - 1, index);

  return root;
}

