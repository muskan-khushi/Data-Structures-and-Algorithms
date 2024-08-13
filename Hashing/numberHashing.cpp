#include <bits/stdc++.h>
using namespace std;

int main() {
    // Step 1: Input the number of elements in the array
    int n;
    cin >> n;

    // Step 2: Declare an array of size 'n' to store the elements
    int arr[n]; // Note: The maximum value any element in this array can have is 12
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input each element of the array
    }

    // Step 3: Precompute frequency of each element
    // We declare a hash array of size 13 (to accommodate values from 0 to 12)
    int hash[13] = {0}; // Initialize all elements to 0
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1; // Increment the count of the current element in the hash array
    }

    // Step 4: Process queries
    int q; // Number of queries
    cin >> q;
    while (q--) {
        int number; // The element whose frequency we want to know
        cin >> number;
        
        // Step 5: Fetch the frequency from the precomputed hash array
        cout << hash[number] << endl; // Output the frequency of the queried number
    }

    return 0;
}
