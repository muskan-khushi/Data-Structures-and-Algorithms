#include <bits/stdc++.h>
using namespace std;

// select minimum and swap

// Given array -> 13, 46, 24, 52, 20, 9
// step-1 -> 9, 46, 24, 52, 20, 13
// swapping at index 0 and minimum index

// step-2 -> 9, 13, 24, 52, 20, 46 //first 2 elements sorted
// swapping at index 1 and minimum index

// step-3 -> 9, 13, 20, 52, 24, 46 //first 3 elements sorted
// swapping at index 2 and minimum index

// step-4 -> 9, 13, 20, 24, 52, 46
// step-5 -> 9, 13, 20, 24, 46, 52

void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

//Best/Worst/Avg Case TC -> O(n^2)

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}