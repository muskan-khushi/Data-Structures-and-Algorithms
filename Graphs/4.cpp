#include <bits/stdc++.h>
using namespace std;

// DEPTH FIRST SEARCH
// using adj list, visited array 
// uses recursion

//sc -> O(N)
//tc -> O(N) + O(2E) for undirected graph

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        //traverse all its neighbours
        for (auto it : adj[node]){
           if (!vis[it]) {
            dfs(it, adj, vis, ls);
           }
        }
    }

public:
    vector<int> dfsOfGraph(int v, vector<int> adj[])
    {
        int vis[v] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};
