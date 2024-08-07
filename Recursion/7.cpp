#include <bits/stdc++.h>
using namespace std;

// Printing all subsequences with a constant sum
// Recursion tree is very important in such problems

void printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    printS(ind + 1, ds, s, sum, arr, n);
    s -= arr[ind];
    ds.pop_back();

    // not pick
    printS(ind + 1, ds, s, sum, arr, n);
}

// print any one subsequence whose sum is given

// technique to print only one answer
// base case => if condition satisfied, return true. if condition not satisfied, return false
// if(f() == true) return true;
// f();
// return false

bool printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        // condition satisfied
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if (printSub(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    s -= arr[ind];
    ds.pop_back();

    // not pick
    if (printSub(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printS(0, ds, 0, sum, arr, n);
    printSub(0, ds, 0, sum, arr, n);
    return 0;
}