#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

// preorder traversal iterative NLR
vector<int> preOrder(Node *root)
{
    stack<Node *> s;
    s.push(root);
    vector<int> ans;

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    return ans;
}

// postorder traversal iterative LRN (reverse of NRL)
vector<int> postOrder(Node *root)
{
    stack<Node *> st;
    st.push(root);
    vector<int> ans;

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// inorder traversal LNR
vector<int> inOrder(Node *root)
{
    stack<Node *> st;
    stack<bool> visited;
    st.push(root);
    vector<int> ans;

    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();
        bool flag = visited.top();
        visited.pop();

        //first time visit
        if (!flag)
        {
            if (temp->right)
            {
                st.push(temp->right);
                visited.push(0);
            }
            st.push(temp);
            visited.push(1);
            if (temp->left)
            {
                st.push(temp->left);
                visited.push(0);
            }
        }

        //second time visit
        else {
            ans.push_back(temp->data);
        }
    }
    return ans;
}
