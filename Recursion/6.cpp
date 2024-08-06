#include <bits/stdc++.h>
using namespace std;

// Function to print all subsequences of the array
// Subsequence is a contiguous or non-contiguous sequence which follows the order.
// For an array [3,1,2], there are a total of 8 subsequences:
// {}, 3, 1, 2, (3,1), (1,2), (3,2), (3,1,2)

// Recursive function to generate and print all subsequences
void printF(int ind, vector<int> &ds, int arr[], int n) {
    // Base case: if the index reaches the end of the array
    if (ind == n) {
        // Print the current subsequence stored in ds
        for (auto it : ds) {
            cout << it << " ";
        }
        // Print empty braces for the empty subsequence
        if (ds.size() == 0) {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // Take or pick the particular index into the subsequence
    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back(); // backtrack to explore the next possibility

    // Not pick or not take the condition, this element is not added to your subsequence
    printF(ind + 1, ds, arr, n);
}

int main() {
    // Example array
    int arr[] = {3, 1, 2};
    int n = 3; // Size of the array

    // Vector to store the current subsequence
    vector<int> ds;

    // Function call to print all subsequences
    printF(0, ds, arr, n);

    return 0;
}

// Time Complexity: O(2^n * n)
// Space Complexity: O(n)
