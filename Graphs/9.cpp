// Detect a cycle in an undirected graph using BFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper function to detect cycle using BFS from a given source node
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;  // Mark the source node as visited
        queue<pair<int, int>> q;  // Queue to perform BFS; stores (node, parent)
        q.push({src, -1});  // Start BFS from source, parent is -1 as it has no parent

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse all adjacent nodes
            for (auto adjacentNode : adj[node])
            {
                // If the adjacent node is not visited, add it to the queue
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;  // Mark as visited
                    q.push({adjacentNode, node});  // Add to queue with current node as parent
                }
                // If the adjacent node is already visited and is not the parent,
                // then there is a cycle in the graph
                else if (parent != adjacentNode) {
                    return true;  // Cycle detected
                }
            }
        }
        return false;  // No cycle found
    }

public:
    // Function to check for cycle in all components of the graph
    bool isCycle(int v, vector<int> adj[])
    {
        int vis[v] = {0};  // Visited array to track visited nodes

        // Loop through all nodes in case the graph is disconnected
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                // Start BFS traversal from unvisited node
                if (detect(i, adj, vis)) {
                    return true;  // If a cycle is found, return true
                }
            }
        }
        return false;  // No cycles found in any component
    }
};

/*
---------------------------
🔍 Example Usage:
---------------------------
int main() {
    int V = 5;
    vector<int> adj[V];

    // Adding undirected edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj);
    cout << (hasCycle ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}
*/

/*
🧠 Time Complexity:
-------------------
- For BFS traversal: Every node and edge is visited once.
- So, Time Complexity = O(V + E)
  where V = number of vertices, E = number of edges

📦 Space Complexity:
-------------------
- Visited array: O(V)
- Queue for BFS: In worst case O(V)
- So, Space Complexity = O(V)
*/
