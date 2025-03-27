#include <bits/stdc++.h>
using namespace std;

//Adjacency Matrix


//Unidrected unweighted graph
int main_undirected_unweighted(){
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<bool> > AdjMat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v;
        AdjMat[u][v] = 1;
        AdjMat[v][u] = 1;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//Undirected weighted graph
int main_undirected_weighted(){
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<int> > AdjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v >> weight;
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//Directed unweighted graph
int main_directed_unweighted(){
    int vertex, edge;
    cin >> vertex >> edge;

    vector<vector<bool> > AdjMat(vertex, vector<bool>(vertex, 0));

    int u, v;
    for (int i = 0; i < edge; i++) {
        cin >> u >> v;
        AdjMat[u][v] = 1;
    }

    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//Directed Weighted Graph
int main_directed_weighted(){
    int vertex, edge;
    cin >> vertex, edge;

    vector<vector<bool> > AdjMat(vertex, vector<bool>(vertex, 0));

    int u, v, weight;

    for (int i=0; i<edge; i++){
        cin >> u >> v >> weight;
        AdjMat[u][v] = weight;
    }

    for (int i=0; i<vertex; i++){
        for (int j=0; j<vertex; j++){
           cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

//TC and SC -> O(v^2)
