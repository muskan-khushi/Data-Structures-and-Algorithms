#include <bits/stdc++.h>
using namespace std;

//BREADTH FIRST SEARCH

//level wise traversal
//always depends on starting node, go level by level based on distance from starting node
//using queue ds and visited array and adj list
//push root node to queue
//keep popping until queue is empty
//while popping, push the immediate unvisted neighbors of the popped element to queue i.e the elements in the vector corresponding to it in the adj list
//keep track of the visited array, keep updating


//sc -> O(N)
//tc -> O(N) + O(2E)

class Solution {
  public:
     vector<int> bfsOfGraph(int V, vector<int> adj[]){
          int vis[V] = {0};
          vis[0] = 1;
          queue<int> q;
          q.push(0);
          vector<int> bfs;

          while (!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
          }
          return bfs;
     }
};


//Code to convert adjacency matrix into adjacency list
// int V = adj.size();
//         vector<vector<int>> adjList(V);
        
//         for (int i=0; i<V; i++){
//             for (int j=0; j<V; j++){
//                 if (adj[i][j] == 1){
//                     adjList[i].push_back(j);
//                 }
//             }
//         }
        