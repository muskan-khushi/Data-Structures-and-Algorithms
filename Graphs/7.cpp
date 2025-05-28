// Flood fill Algorithm

// You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

// Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Helper DFS function to fill connected components
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image,
             int newColor, int iniColor, int delRow[], int delCol[]) {

        // Change the color of the current pixel to the new color
        ans[sr][sc] = newColor;

        int n = image.size();       // Total number of rows
        int m = image[0].size();    // Total number of columns

        // Check in all 4 directions: up, right, down, left
        for (int i = 0; i < 4; i++) {
            int nrow = sr + delRow[i];   // new row index
            int ncol = sc + delCol[i];   // new column index

            // Check if new position is within bounds
            // Also check if the new cell has the same initial color (i.e., is part of the region)
            // and is not already colored with newColor to avoid re-processing
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                
                // Recursively call DFS for the next valid neighboring cell
                dfs(nrow, ncol, ans, image, newColor, iniColor, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Get the initial color of the starting pixel
        int iniColor = image[sr][sc];

        // Optimization: if the initial color is already the new color, return the original image
        if (iniColor == newColor)
            return image;

        // Make a copy of the original image to store the result
        vector<vector<int>> ans = image;

        // Arrays to help move in the 4 directions (up, right, down, left)
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Start the DFS from the source pixel
        dfs(sr, sc, ans, image, newColor, iniColor, delRow, delCol);

        // Return the modified image
        return ans;
    }
};

//tc -> O(N*M)
//sc -> O(N*M)
