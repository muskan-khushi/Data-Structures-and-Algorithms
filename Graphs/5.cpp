#include <bits/stdc++.h>
using namespace std;

// GFG : Number of Provinces
//  Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

// Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

//SC -> O(N) + O(N)
//TC -> O(N) + O(V + 2E)

class Solution
{
private:
    void dfs(int node, vector<int> adjLs[], int vis[]){
        vis[node] = 1;
        for (auto it : adjLs[node]){
            if (!vis[it]){
                dfs(it, adjLs, vis);
            }
        }
    }
public:
    int numberOfProvinces(vector<vector<int>> adj, int V)
    {
        vector<int> adjLs[V];
        for (int i=0; i<V; i++){
            for (int j=0; j<V; j++){
                if (adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int cnt = 0;

        for (int i=0; i<V; i++){
            if (!vis[i]) {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};