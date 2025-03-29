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

//vertical traversal of binary tree

//pehle print -> jiska index kam ho
//if index same, jiska level kam ho

//using level order traversal and 2 2d arrays
//tc-> O(N)   //sc -> O(N)
void find(Node* root, int pos, int &l, int &r){
    if (root == NULL) return;
    l = min(l, pos);
    r = max(r, pos);
    find(root->left, pos-1, l, r);
    find(root->right, pos+1, l, r);
}

vector<int> vertical(Node* root){
    int l = 0, r = 0;
    find(root, 0, l, r);
    vector<vector<int>> positive(r+1);
    vector<vector<int>> negative(abs(l)+1);
    vector<int> ans;

    queue<Node*> q;
    queue<int> index;
    q.push(root);
    index.push(0);

    while (!q.empty()){
        Node* temp = q.front();
        q.pop();
        int pos = index.front();
        index.pop();
        if(pos >= 0){
            positive[pos].push_back(temp->data);
        }
        else negative[abs(pos)].push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
            index.push(pos - 1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(pos + 1);
        }
       
        for(int i = negative.size(); i>0; i--){
            for (int j=0; j<negative[i].size(); j++){
                ans.push_back(negative[i][j]);
            }
        }
        for (int i=0; i<positive.size(); i++){
            for (int j=0; j<positive[i].size(); j++){
                ans.push_back(positive[i][j]);
            }
        }
    }
    return ans;
}

//diagonal traversal
//using preorder traversal NLR
void find1(Node* root, int pos, int& l){
    if(root == NULL) return;
    l = max(pos, l);
    find1(root->left, pos+1, l);
    find1(root->right, pos, l);
}

void findDiag(Node* root, int pos, vector<vector<int>>& ans){
    if (root == NULL) return;
    ans[pos].push_back(root->data);
    findDiag(root->left, pos+1, ans);
    findDiag(root->right, pos, ans);
}

vector<int> diagonal(Node* root){
    int l = 0;
    find1(root,0,l);
    vector<vector<int>> ans(l+1);
    findDiag(root, 0, ans);
    vector<int> temp;
    for (int i=0; i<ans.size(); i++){
        for (int j=0; j<ans[i].size(); j++){
            temp.push_back(ans[i][j]);
        }
    }
    return temp;
}


//boundary traversal
//1. root node ko answer
//2. left subtree traverse, add until leaf node
//3. add leaf node
//4. right subtree traverse, add in reverse order

void leftSub(Node* root, vector<int>& ans){
    if(!root || (!root->left && !root->right)) return;

    ans.push_back(root->data);
    if(root->left) leftSub(root->left, ans);
    else leftSub(root->right, ans);
}

void leaf(Node* root, vector<int>& ans){
    if(root== NULL) return;
    if(!root->left && !root->right){
        ans.push_back(root->data);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}

void rightSub(Node* root, vector<int>& ans){
    if(!root || (!root->left && !root->right)) return;
    if(root->right) rightSub(root->right, ans);
    else rightSub(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    //root element
    ans.push_back(root->data);
    //left boundary ko daal do except leaf
    leftSub(root->left, ans);
    //leaf ko insert kara do
    if(root->left || root->right)  leaf(root, ans);
    //right boundary ko reverse order mei daal do except leaf node
    rightSub(root->right, ans);

    return ans;
}