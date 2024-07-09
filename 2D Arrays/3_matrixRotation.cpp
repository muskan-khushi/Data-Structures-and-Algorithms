#include <bits/stdc++.h>
using namespace std;

// Rotate Matrix by 90 deg clockwise
// Time Complexity -> O(N^2)

// BruteForce Approach -> by allocating a new matrix
// SC - O(N^2)
// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < n; j++)
//     {
//         ans[j][n-1-i] = matrix[i][j];
//     }
// }

// Optimal Solution ->
// SC - O(1)
//(col->reverse) of matrix = row of ans
// Transpose and then reverse each row

void rotate90CW(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse Each Row
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            swap(matrix[i][left], matrix[i][right]);
            left++;
            right--;
        }
    }
}



//Rotate a matrix by 180 deg
//Approach -> Rotate the matrix twice by 90 CW
void rotate180(vector<vector<int>> matrix)
{
    int n = matrix.size();

    for (int x = 1; x <= 2; x++)
    {
        // Transpose
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse Each Row
        for (int i = 0; i < n; i++)
        {
            int left = 0;
            int right = n - 1;
            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
}
//OR another approach can be -> Reverse all columns and then reverse each row



//Rotate Matrix by 90deg ACW
//Approach -> Transpose and then reverse each column
  void rotateBy90ACW(vector<vector<int> >& matrix, int n) 
    { 
        // code here 
        
        //transpose
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //column reverse
        for (int j=0; j<n; j++){
            int start = 0;
            int end = n-1;
            
            while(start<=end){
                swap(matrix[start][j], matrix[end][j]);
                start++;
                end--;
            }
        }
    } 

int main()
{

    return 0;
}