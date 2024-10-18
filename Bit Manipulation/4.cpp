#include <bits/stdc++.h>
using namespace std;

//-------------------Single Number - 1----------------
// Function to find the element that appears only once in the array
// All other elements appear twice
// Approach: Use a frequency map to track the occurrence of each number
// Time Complexity: O(N) | Space Complexity: O(N)
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> freqMap;  // Map to store the frequency of each element

    // Step 1: Count the frequency of each number in the array
    for (int i = 0; i < nums.size(); i++) {
        freqMap[nums[i]]++;  // Increment the frequency of the current number
    }

    // Step 2: Find the number that appears only once
    for (auto it : freqMap) {
        if (it.second == 1) {  // If frequency is 1, this is the single number
            return it.first;
        }
    }

    return -1;  // Return -1 if no single element is found (this case should not occur given the problem constraint)
}

// Optimal Solution using XOR
// Function to find the element that appears only once using XOR
// Time Complexity: O(N) | Space Complexity: O(1)
int singleNumber1XOR(vector<int>& nums) {
    int result = 0;  // Initialize result to 0

    // XOR all elements in the array
    for (int i = 0; i < nums.size(); i++) {
        result ^= nums[i];  // XOR the current number with the result
    }

    return result;  // The remaining number is the single number
}


//------------------Single Number - 2------------------
// Every number is appearing thrice except one number
// Approach: Sort the array and then check every third element
// Time Complexity: O(NlogN + N/3) | Space Complexity: O(1)
// Disadvantage: Sorting distorts the input order
int singleNumber2(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Step 1: Sort the array
    for (int i = 0; i < nums.size(); i += 3) {
        // If the current element is different from the next one, it's the unique element
        if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
            return nums[i];  // Return the unique element
        }
    }
    return -1;  // Return -1 if no single element is found (this case should not occur given the problem constraint)
}

// More Optimal Solution using Bit Manipulation
// Every number appears three times except one element
// Time Complexity: O(N) | Space Complexity: O(1)
// Concept of "buckets" using bit manipulation
int singleNumber2Optimal(vector<int>& nums) {
    // Initialize three variables to keep track of bits appearing once, twice, and thrice.
    int ones = 0, twos = 0, threes = 0;

    // Traverse through all the numbers in the array.
    for (int num : nums) {
        // Update 'twos': Accumulate bits that appear twice
        twos |= ones & num;

        // Update 'ones': Accumulate bits that appear once
        ones ^= num;

        // Identify the bits that have appeared three times
        threes = ones & twos;

        // Clear bits that have appeared three times from both 'ones' and 'twos'
        ones &= ~threes;
        twos &= ~threes;
    }

    // After the loop, 'ones' will hold the number that appeared exactly once.
    return ones;
}

// Main function implementation
int main() {
    // Test case for "Single Number - 1" where all elements appear twice except one
    vector<int> nums1 = {2, 2, 3, 4, 4};  // The element 3 appears only once
    cout << "Single number (appears once, others twice) using map: " << singleNumber(nums1) << endl;
    cout << "Single number (appears once, others twice) using XOR: " << singleNumber1XOR(nums1) << endl;

    // Test case for "Single Number - 2" where all elements appear thrice except one
    vector<int> nums2 = {2, 2, 2, 3, 4, 4, 4};  // The element 3 appears only once

    // Approach 1: Sort-based solution (not as efficient but works)
    cout << "Single number (appears once, others thrice) using sorting: " << singleNumber2(nums2) << endl;

    // Approach 2: Optimal solution using bit manipulation
    cout << "Single number (appears once, others thrice) using optimal bit manipulation: " << singleNumber2Optimal(nums2) << endl;

    return 0;
}
