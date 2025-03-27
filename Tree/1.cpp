#include <bits/stdc++.h>
using namespace std;

//It is a type of data structure that represents a hierarchial relationship between data elements called nodes.

//Binary tree is a non linear data structure where each node has at most two children. 

//Terminologies - node, root, parent, child, leaf(node with no child), edges, ancestor, descendant, level, sibling, height, degree

//n nodes
//n-1 edges

//Creation of Tree(through level order traversal)
//1. create root node
//2. left child
//3. right child

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left=right=NULL;
    }
};

int main(){

    int x;
    cout << "Enter the root element: ";
    cin>>x;
    int first, second;
    queue<Node*>q;
    Node* root = new Node(x);
    q.push(root);

    //Build a binary tree
    //level wise
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << "Enter the left child of "<<temp->data<<" : ";
        cin >> first; //left node ki value
        //left node
        if (first != -1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        //right node
        cout << "Enter the right child of "<<temp->data<<" : ";
        cin>>second;
        if (second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
     
    return 0;
}