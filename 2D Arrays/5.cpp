#include <bits/stdc++.h>
using namespace std;

// How to store 2 numbers in one position
// Given N is any number between 1 to 99
// Store N and its number of occurrences in 1 int block a
// Let N = 2 and it occurs 6 times
//  take 99 + 1 = 100
// Store a = occ*100 + N = 6*100 + 2 = 602
// To extract the original number and occ from what is stored-
//  N = a%100 = 602%100 = 2
//  occ = a/100 = 602/100 = 6



// Find Missing and Repeating [GFG]
// Make another array to store the count of each number.

// More optimized approach in terms of space complexity
// without creating extra array
// TC = O(N), SC = O(1)
vector<int> findTwoElement(vector<int> arr, int n)
{
    vector<int> ans;
    int missing;
    int repeating;
    for (int i = 0; i < n; i++)
    {
        arr[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }
    // Missing Number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n == 0)
        {
            missing = i + 1;
            break;
        }
    }
    // Repeating Number
    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n == 2)
        {
            repeating = i + 1;
            break;
        }
    }
    ans.push_back(repeating);
    ans.push_back(missing);

    return ans;
}

// Count frequency/number of occurrences of number [GFG]**

// Majority Element
// More voting algorithm when any element is clearly more than n/2 times
// TC -> O(N) and SC -> O(1)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int candidate, count = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else {
                if (candidate == nums[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return candidate;
    }
};


int main()
{

    return 0;
}