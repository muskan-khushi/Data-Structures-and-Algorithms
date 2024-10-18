#include <bits/stdc++.h>
using namespace std;

//-----Minimum Bit Flips to convert a number------
//TC -> O(log2(start^goal))
//SC -> O(1)
int minBitFlips(int start, int goal){
    int ans = start ^ goal;
    int cnt = 0;
    for (int i=0; i<=31; i++){
        if (ans & (1<<i))
        cnt++;
    }
    return cnt;
}


//------Power Set (Printing all Subsets)-------
//2^n is equivalent to 1<<n

//Logic:
//nums = [1 2 3]
//        0 1 2

//       2   1   0

//0 ->   0   0   0   -> []
//1 ->   0   0   1   -> [1]
//2 ->   0   1   0   -> [2]
//3 ->   0   1   1   -> [1,2]
//4 ->   1   0   0   -> [3]
//5 ->   1   0   1   -> [1,3]
//6 ->   1   1   0   -> [2,3]
//7 ->   1   1   1   -> [1,2,3]

//Put all these lists into a bigger list which we have to return.

//TC-> O(N * 2^n)
//SC -> O(N * 2^n)
void printPowerSet(vector<int> arr) {
    int n = arr.size();        // Size of the input array
    int powerSetSize = 1 << n; // Total subsets = 2^n (achieved by left-shifting 1 by n)

    // Print the opening brace for the power set
    cout << "{ ";
    
    // Loop through all subsets represented by binary numbers from 0 to 2^n - 1
    for (int i = 0; i < powerSetSize; i++) {
        cout << "{ ";  // Start of the current subset

        // Check each bit position in the binary representation of 'i'
        for (int j = 0; j < n; j++) {
            // If the j-th bit of 'i' is set, include arr[j] in the current subset
            if (i & (1 << j)) {
                cout << arr[j] << " ";  // Add the corresponding element from the array
            }
        }

        // End of the current subset
        cout << "}";
        
        // Add a comma after each subset, except the last one
        if (i < powerSetSize - 1) {
            cout << ", ";
        }
    }

    // Print the closing brace for the power set
    cout << " }" << endl;
}

int main(){

    return 0;
}