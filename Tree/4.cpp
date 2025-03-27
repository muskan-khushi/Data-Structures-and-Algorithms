#include <bits/stdc++.h>
using namespace std;

class Node{
 public:
  int data;
  Node* left;
  Node* right;

  Node(int value){
    left = right = NULL;
    data = value;
  }
};

//Check if two trees are identical
//TC and SC-> O(n)
bool isIdentical(Node* r1, Node* r2){
    if (r1 == NULL && r2 == NULL) return 1;
    
    if((!r1 && r2) && (r1 && !r2)) return 0;
    
    if (r1->data != r2->data) return 0;

    bool ans = isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);

    return ans;
}

//Convert into mirror tree
//right left mei, left right mei har node mei
//TC -> O(n)
void mirrorTree(Node* root){
   if(root == NULL) return;

   Node *temp = root->right;
   root->right = root->left;
   root->left = temp;

   mirrorTree(root->left);
   mirrorTree(root->right);
}

//Check for Balance Tree
//height of left subtree - height of right subtree = {-1,0,1} for all nodes
int height(Node* root, int &valid){
    if (root == NULL) return 0;

    int L = height(root->left, valid);
    int R = height(root->right, valid);
    if (abs(L-R) > 1) valid = 0;
    return 1 + max(L,R);
}
bool balanceTree(Node* root){
    int valid = true;
    height(root, valid);
    return valid;
}

//Level Order Traversal in Spiral Form
//Agar R to L jaa rhe toh element bhi R to L insert karenge, likewise for L to R
//TC -> O(N) SC->O(N)
vector<int> LevelOrderSpiral(Node* root){
    stack<Node*> s1; //L to R
    stack<Node*> s2; //R to L
    
    s1.push(root);
    vector<int> ans;

    while (!s1.empty() || !s2.empty()){
        //R to L
        if (!s1.empty()){
            while (!s1.empty()){
                Node* temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if (temp->right) s2.push(temp->right);
                if(temp->left) s2.push(temp->left);
            }
        }

        //L to R
        else {
            while(!s2.empty()){
                Node*temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if(temp->left) s1.push(temp->left);
                if(temp->right) s1.push(temp->right);
            }
        }
    }
    return ans;
}

//check if two nodes are cousin
//same level but different parents
bool parent(Node* root, int a, int b){
    if(root->left && root->right){
        if (root == NULL) return 0;

        if(root->left->data == a && root->right->data == b) return 1;
        if(root->left->data == b && root->right->data == a) return 1;

        return(parent(root->left, a, b) ||
        parent(root->right, a, b));
    }
}

bool isCousin(Node* root, int a, int b){
    queue<Node*> q;
    q.push(root);

    int l1 = -1, l2 = -1;
    int level = 0;
    while (!q.empty()){
        int n = q.size();
        while (n--){
            Node* temp = q.front();
            q.pop();
            if(temp->data == a) l1 = level;
            if(temp->data == b) l2 = level;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        level++;
        if(l1 != l2) return 0;

        if(l1 != -1) break;

        return !parent(root, a, b);
    }

}
