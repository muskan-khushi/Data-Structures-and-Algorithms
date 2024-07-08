#include <bits/stdc++.h>
using namespace std;

// Printing a 2D array 

//Row wise
void printRow(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printCol(int arr[][4], int row, int col)
{
    // Column wise
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printRowMax(int arr[][4], int row, int col)
{
    int index = -1, sum = INT_MIN;

    for (int i = 0; i < row; i++)
    {
        int total = 0;
        for (int j = 0; j < col; j++)
        {
            total += arr[i][j];
        }
        if (total > sum)
        {
            sum = total;
            index = i;
        }
    }
    cout << index;
}

void printSumDiagonal(int matrix[][3], int row, int col)
{
    int first = 0;
    int sec = 0;

    // first diagonal sum
    int i = 0;
    while (i < row)
    {
        first += matrix[i][i];
        i++;
    }

    // second diagonal sum
    i = 0;
    int j = col - 1;
    while (j >= 0)
    {
        sec += matrix[j][j];
        i++, j--;
    }

    cout << first << " " << sec;
}

// Function to reverse each row of the matrix
void reverseRow(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int start = 0;
        int end = col - 1;

        while (start < end)
        {
            // Swap the elements at the start and end indices
            int temp = arr[i][start];
            arr[i][start] = arr[i][end];
            arr[i][end] = temp;

            start++;
            end--;
        }
    }
}

int main()
{

    // How are elements of 2D array stored in memory?

    // 1. Row Major - stored row wise, 1st row all elements stored, then 2nd row all elements and so on in contiguous memory locations
    // hence stored in memory as linear array only
    // Index at which element is stored in linear array/memory = row-index*column + col-index
    // Finding row-index and col-index with given memory index, row and col
    // row-index = index/column
    // col-index = index%column
    // arr[i][j] = base_address + (i*col + j) * size of element

    // int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Update or user input
    // arr[3][0] = 15;
    // cin >> arr[1][2];

    //Printing a 2D array row wise
    // printRow(arr,3,4);

    // Printing a 2D array col wise
    //   printCol(arr,3,4);

    // Find an Element in Array
    // int x = 7;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         if (arr[i][j] == x)
    //         {
    //             cout << "yes";
    //             return 0;
    //         }
    //     }
    // }
    // cout << "no";

    // Add 2 Matrix
    //  int row;
    //  int col;

    // int sum[3][4];
    // int arr1[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
    // int arr2[3][4]={0,1,3,4,6,7,10,11,41,18,9,11};

    // for (int i=0; i<3; i++){
    //     for (int j=0; j<4; j++){
    //         sum[i][j] = arr1[i][j] + arr2[i][j];
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Print Row Index with Max Sum
    //  printRowMax(arr1, 3, 4);

    // Print Sum of Diagonal Element
    //  int matrix[3][3] = {1,2,3,4,5,6,7,8,9};
    //  printSumDiagonal(matrix, 3, 3);

    // Reverse each row of Matrix
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    reverseRow(arr, 3, 4);
    printRow(arr,3,4);

    return 0;
}