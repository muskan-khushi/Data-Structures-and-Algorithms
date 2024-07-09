#include <bits/stdc++.h>
using namespace std;

void wave(int arr[][4], int row, int col){
    for (int j=0; j<col; j++){
        //
        if (j%2 == 0) {
            for (int i=0; i<row; i++){
                cout << arr[i][j] << " ";
            }
        }
        else {
            for (int i=row-1; i>=0; i--){
                cout << arr[i][j] << " ";
            }
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> matrix){
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int top = 0;
    int bottom = row-1;
    int left = 0;
    int right = col-1;

    while (top <= bottom && left <= right){
        //print top
        for (int j= left; j<=right; j++){
            ans.push_back(matrix[top][j]);
        }
         top++;
        //print right
        for (int i= top; i<= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
         right--;
        //print bottom
        if (top <= bottom){
        for (int j= right; j>=left; j--){
            ans.push_back(matrix[bottom][j]);
        }
        bottom--;
        }
        //print left
        if (left <= right){
            for (int i= bottom; i>= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

void transposeMatrix (vector<vector<int>> matrix, int n) {
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i=0; i<row-1; i++){
        for (int j=i+1; j<col; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

//2. Column Major
//stored column wise in memory as linear array
//find formula for memory index

//Vector in 2D

//create and initialize a 2D vector
//vector<vector<int>> matrix(rows, vector<int>(col, initializer));
// int n, m;
// cout << "Enter rows and columns: ";
// cin >> n >> m;
// vector<vector<int>> matrix(n, vector<int>(m, 1));

// for (int i=0; i<3; i++){
//     for (int j=0; j<4; j++){
//         cout << matrix[i][j] << " ";
//     }
//     cout << endl;
// }

//update value
// matrix[1][2] = 5;
// cin >> matrix[2][2];

//find number of rows and columns
// cout << "Rows: " << matrix.size() << endl;
// cout << "Columns: " << matrix[0].size() << endl;

// //Taking input in 2D array
// for (int i=0; i<n; i++){
//     for (int j=0; j<m; j++){
//         cin >> matrix[i][j];
//     }
// }

// //Printing 2D array
// for (int i=0; i<n; i++){
//     for (int j=0; j<m; j++){
//         cout << matrix[i][j] << " ";
//     }
//     cout << endl;
// }

//Wave Form
//col even -> up to down
//col odd -> down to up
//Time Complexity = O(row*col)
//Space Complexity = O(1)

//Spiral Form
//pehle top most row print karao, phir rightmost col, phir bottom most row, phir left most col
//Time Complexity -> O(row*col)
//Space Complexity -> O(1)

//Transpose of a Matrix without making a new matrix
//Time Complexity -> O(N^2)
//Space Complexity -> O(1)

int main(){

int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
wave(arr,3,4);


    return 0;
}