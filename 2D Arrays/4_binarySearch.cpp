#include <bits/stdc++.h>
using namespace std;

// Binary Search in 2D Arrays

bool searchMatrix1(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        if (matrix[i][0] <= target && target <= matrix[i][col - 1])
        {
            // Binary Search
            int start = 0;
            int end = col - 1;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;

                if (matrix[i][mid] == target)
                {
                    return true;
                }

                if (matrix[i][mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            return false;
        }
    }

    return false; // If target is not found in any row
}


// OR a more optimized sol would be
// consider it as 1D array in row major order and then apply BS
bool searchMatrix2(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    if (rows == 0)
        return false; // Check if matrix is empty
    int cols = matrix[0].size();

    int start = 0;
    int end = rows * cols - 1;
    int mid, rowIndex, colIndex;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        rowIndex = mid / cols;
        colIndex = mid % cols;

        if (matrix[rowIndex][colIndex] == target)
        {
            return true;
        }
        else if (matrix[rowIndex][colIndex] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

//Search in Sorted Row Col Wise Matrix
bool search(vector<vector<int>> matrix, int n, int m, int x){
    int row = 0, col = m-1;

    while (row<n && col>=0){
        if(matrix[row][col]==x){
            return 1;
        }
        else if(matrix[row][col]<x){
            row++;
        }
        else {
            col--;
        }
        return 0;
    }
}

int main()
{

    return 0;
}