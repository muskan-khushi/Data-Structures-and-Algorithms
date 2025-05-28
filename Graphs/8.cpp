// Rotten Oranges

// Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cell have fresh oranges
// 2 : Cell have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

// Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int n = grid.size();           // number of rows
        int m = grid[0].size();        // number of columns

        // Queue for BFS traversal
        // Each element stores: {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;

        // Visited matrix to keep track of which oranges have turned rotten
        // Initialize with 0 (unvisited/fresh), and mark rotten with 2
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Step 1: Add all initially rotten oranges to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});   // Add to BFS queue with time = 0
                    vis[i][j] = 2;         // Mark as visited/rotten
                } else {
                    vis[i][j] = 0;         // Fresh or empty, not visited yet
                }
            }
        }

        // Direction arrays for traversing up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        // Variable to store the final time taken to rot all reachable oranges
        int tm = 0;

        // Step 2: Start BFS traversal
        while (!q.empty()) {
            // Extract the front cell from the queue
            int r = q.front().first.first;     // current row
            int c = q.front().first.second;    // current col
            int t = q.front().second;          // time when it became rotten
            q.pop();

            // Update the maximum time so far
            tm = max(tm, t);

            // Visit all 4 adjacent cells
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];    // neighbor row
                int ncol = c + dcol[i];    // neighbor col

                // Check if the adjacent cell is within bounds
                // and if it is a fresh orange not yet rotten
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {

                    // Rot this orange and add it to the queue with time + 1
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;   // Mark it as rotten now
                }
            }
        }

        // Step 3: After BFS, check if any fresh orange was never visited (still fresh)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If an orange is still fresh and was never rotten
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;  // Not all oranges can be rotten
                }
            }
        }

        // Step 4: Return the time taken to rot all oranges
        return tm;
    }
};

// ✅ Time Complexity Analysis:
// Let:

// n = number of rows

// m = number of columns

// Time Complexity = O(n × m)

// Why?

// We loop over every cell once in the beginning to find all rotten oranges → O(n * m)

// Each cell is processed at most once in the BFS → O(n * m)

// Final loop to check for unrotted fresh oranges → O(n * m)

// Total operations are linear in the number of cells → O(n * m)

// ✅ Space Complexity Analysis:
// Space Complexity = O(n × m)

// Why?

// vis array of size n × m → O(n * m)

// Queue can contain at most n * m elements in the worst case → O(n * m)

// Other variables take constant space

// 🧠 Summary:
// ✅ Multi-source BFS starting from all rotten oranges

// ✅ Queue tracks both location and the time it took to rot

// ✅ Visited array ensures oranges are only processed once

// ✅ Final check ensures no orange is left unrotted