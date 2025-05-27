#include <bits/stdc++.h>
using namespace std;

//GFG Number of Islands
// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

// Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

//SC-> O(N^2)
//TC -> O(N^2)

class Solution {
private:
    // Helper function to perform BFS and mark all connected land cells
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        // Mark the starting cell as visited
        vis[row][col] = 1;

        // Initialize a queue for BFS
        queue<pair<int, int>> q;
        q.push({row, col});

        // Get the size of the grid
        int n = grid.size();
        int m = grid[0].size();

        // Start BFS traversal
        while (!q.empty()) {
            // Get the front cell from the queue
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse all 8 possible neighbors (including diagonals)
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    // Check if the neighbor is within bounds,
                    // is land ('1'), and has not been visited
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        
                        // Mark the neighbor as visited and push it to the queue
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    // Main function to count the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();          // Number of rows
        int m = grid[0].size();       // Number of columns

        // Create a visited matrix initialized with 0 (false)
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;  // Counter for number of islands

        // Traverse the entire grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If the current cell is land and not visited
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;  // Found a new island
                    bfs(row, col, vis, grid);  // Mark all its parts using BFS
                }
            }
        }

        // Return the total number of islands found
        return cnt;
    }
};
