// Detect a cycle in an undirected graph using DFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function: returns true if cycle is detected starting from 'node'
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;  // Mark current node as visited

        // Traverse all adjacent (connected) nodes
        for (auto adjacentNode : adj[node])
        {
            // If the adjacent node is not visited, recursively DFS on it
            if (!vis[adjacentNode])
            {
                if (dfs(adjacentNode, node, vis, adj))
                {
                    return true;  // Cycle found in DFS subtree
                }
            }
            // If the adjacent node is visited and it's not the parent,
            // it means a cycle is found
            else if (adjacentNode != parent)
            {
                return true;
            }
        }

        // No cycle found starting from this node
        return false;
    }

public:
    // Main function to check for a cycle in any component of the graph
    bool isCycle(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);  // Visited array initialized to 0

        // Handle disconnected graphs by running DFS for every unvisited node
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis, adj))  // Start DFS with parent = -1
                {
                    return true;  // Cycle detected
                }
            }
        }

        return false;  // No cycle in any component
    }
};
