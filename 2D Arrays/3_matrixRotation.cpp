#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>> matrix, int n){
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}


// Rotate Matrix by 90 deg clockwise
// Time Complexity -> O(N^2)

// BruteForce Approach -> by allocating a new matrix
//SC - O(N^2)
// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < n; j++)
//     {
//         ans[j][n-1-i] = matrix[i][j];
//     }
// }

//Optimal Solution -> 
//SC - O(1)
//(col->reverse) of matrix = row of ans
//pehle transpose
//then reverse each row

void rotateMatrix90CW(vector<vector<int>> matrix, int n){
    transpose(matrix, n);
    for (int i=0; i<n; i++){
        int left = 0;
        int right = n-1;
        while (left<=right){
            swap(matrix[i][left],matrix[i][right]);
            left++;
            right--;
        }
    }
}

int main()
{

    return 0;
}