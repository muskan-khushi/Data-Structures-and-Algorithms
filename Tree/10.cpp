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

//Burning Tree
//starting from root node:
//1.agar aapki side se burn aa rha toh bta do mujhe jalne mei kitne sec hain
//2. agar nhi aa rha toh height bta do apni side ki
//burn ko negative sign se represent karenge to differentiate from height

int burn(Node* root, int& timer, int target){
    //exist na kare
    if(!root) return 0;
    //exist
    //target node
     if(root->data == target) return -1;

     int left = burn(root->left, timer, target);
     int right = burn(root->right, timer, target);

     //burn ki condition
     if(left < 0){
        timer = max(timer, abs(left)+right);
        return left-1;
     }
     if(right < 0){
        timer = max(timer, abs(right)+left);
        return right-1;
     }

     //height ko return karna hai
     return(1+max(left,right));

}

void find(Node* root, int target, Node* &burnNode){
    if(!root) return;
    if(root->data == target) {
        burnNode = root;
        return;
    }
    find(root->left, target, burnNode);
    find(root->right, target, burnNode);
}

int height(Node* root){
    if(!root) return 0;
    return 1+max(height(root->left),height(root->right));
}

int minTime (Node* root, int target){
    int timer = 0;
    burn(root, timer, target);

    //height of target node ki if we consider it as root node
    Node* burnNode = NULL;
    find(root, target, burnNode);

    int high = height(burnNode)-1;

    return max(timer, high);

}


//Maximum path sum between two special nodes
int maxSum(Node* root, int& sum){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return root->data;

    int left = maxSum(root->left, sum);
    int right = maxSum(root->right, sum);

    if(root->left && root->right){
        sum = max(sum, root->data+left+right);
        return root->data + max(left, right);
    }
    else if(root->left && !root->right){
        return root->data + left;
    }
    else {
        return root->data + right;
    }
}

int maxSumMain(Node* root){
    int sum = INT_MIN;
    int val = maxSum(root, sum);
    if(root->left && root->right) return sum;

    return max(val, sum);
}