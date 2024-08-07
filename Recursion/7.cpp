#include <bits/stdc++.h>
using namespace std;

//TC -> O(N)

// Function to print all subsequences with a given sum
// This function uses recursion to explore all possible subsequences
void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // Base case: if the end of the array is reached
    if (ind == n)
    {
        // If the current sum matches the target sum, print the subsequence
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    // Include the current element in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];

    // Recursive call to include the next element
    printS(ind + 1, ds, s, sum, arr, n);

    // Backtrack: remove the current element from the subsequence
    s -= arr[ind];
    ds.pop_back();

    // Recursive call to exclude the next element
    printS(ind + 1, ds, s, sum, arr, n);
}

// Function to print any one subsequence whose sum is equal to the given sum
// This function uses a boolean return type to terminate early when a valid subsequence is found
bool printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    // Base case: if the end of the array is reached
    if (ind == n)
    {
        // If the current sum matches the target sum, print the subsequence
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true; // Return true as we found a valid subsequence
        }
        else
            return false; // Return false as no valid subsequence is found
    }

    // Include the current element in the subsequence
    ds.push_back(arr[ind]);
    s += arr[ind];

    // Recursive call to include the next element
    if (printSub(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    // Backtrack: remove the current element from the subsequence
    s -= arr[ind];
    ds.pop_back();

    // Recursive call to exclude the next element
    if (printSub(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false; // Return false if no valid subsequence is found
}

// Function to count the number of subsequences whose sum is equal to the given sum
int printCount(int ind, int s, int sum, int arr[], int n)
{
    // Base case: if the end of the array is reached
    if (ind == n)
    {
        // Return 1 if the current sum matches the target sum
        if (s == sum)
            return 1;
        else
            return 0; // Return 0 if no valid subsequence is found
    }

    // Include the current element in the sum
    s += arr[ind];
    int l = printCount(ind + 1, s, sum, arr, n);

    // Backtrack: exclude the current element from the sum
    s -= arr[ind];
    int r = printCount(ind + 1, s, sum, arr, n);

    return l + r; // Return the total count of valid subsequences
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;

    // Print all subsequences with the given sum
    cout << "All subsequences with sum " << sum << ":\n";
    printS(0, ds, 0, sum, arr, n);

    // Print any one subsequence with the given sum
    cout << "\nOne subsequence with sum " << sum << ":\n";
    printSub(0, ds, 0, sum, arr, n);

    // Print the count of subsequences with the given sum
    cout << "\nCount of subsequences with sum " << sum << ":\n";
    cout << printCount(0, 0, sum, arr, n) << endl;

    return 0;
}
