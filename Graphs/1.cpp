#include <bits/stdc++.h>
using namespace std;

//nodes cannot be repeated in a path
//total degree of an undirected graph = 2*no. of edges
//degree of a directed graph in terms of in degree and out degree

//Graph Representation

//Input 
//n->nodes m->edges
//edges given

//Store
//Matrix-> adjacency matrix-> adj[n+1][m+1]-> v to v
//         tells if there is an edge between two particular nodes
//space -> O(N^2) costly

int main1(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}

int main2(){
    //adjacency list -> O(2E) space
    //corresponding to every item in list an empty vector which will later store all the neighbours of that node
    int n,m;
    vector<int> adj[n+1];
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}

//in case of directed graph,
//sc -> O(E)
//adj[v].push_back(u) not used

//for weighted graph, instead of 1 ue weight in adjacency matrix
//in adj list, use pairs in vector, pairs of vertex and edge weight


