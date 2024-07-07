#include <bits/stdc++.h>
using namespace std;

//1. Pick a pivot and place it in its current place in the sorted array
//pivot can be any element
//2. Smaller on the left, larger on the right.
//3. Repeat

//[4, 6, 2, 5, 7, 9, 1, 3]
//in this case, pivot is first element (you can take any)
//[2, 1, 3, 4, 6, 5, 7, 9]
//[2, 1, 3] //left part -> separate array
//[1, 2, 3] 
//[1, 2, 3, 4, 6, 5, 7, 9] \\left part sorted
//[6, 5, 7, 9] //sorting the right part
//[5, 6, 7, 9]
//[5] and [7, 9]
//[7, 9]
//[1, 2, 3, 4, 5, 6, 7, 9] //SORTED

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr) {
    qs(arr, 0, arr.size() - 1);
    return arr;
}


int main() {

    return 0;
}

//Time Complexity - O(N log N)
//Space Complexity - O(1)