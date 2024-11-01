//-----------Single Number 3--------------------
//All numbers occurring twice except two numbers occurring once. Find 2 numbers

#include <iostream>
#include <vector>

using namespace std;  // Use the standard namespace to avoid prefixing std::

// Function to find the two unique numbers in an array where every other number appears twice
pair<int, int> findTwoSingleNumbers(const vector<int>& nums) {
    int xor_all = 0;  // This will hold the XOR of the two unique numbers

    // Step 1: XOR all numbers in the array.
    // The result will be the XOR of the two unique numbers, say x and y.
    // This is because all other numbers appearing twice will cancel out (since a ^ a = 0).
    for (int num : nums) {
        xor_all ^= num;  // XOR every number in the array
    }

    // At this point, xor_all = x ^ y, where x and y are the two unique numbers.

    // Step 2: Find the rightmost set bit (bit that is 1) in xor_all.
    // This set bit corresponds to a position where x and y differ.
    // Using the operation xor_all & -xor_all isolates the rightmost set bit.
    // -xor_all is the two's complement of xor_all, which flips all the bits and adds 1.
    int set_bit = xor_all & -xor_all;

    // Now, set_bit contains the rightmost bit where x and y differ.
    // We will use this bit to separate the numbers into two groups (or "buckets").

    // Step 3: Divide the numbers into two groups (buckets) based on the rightmost set bit.
    // - Bucket 1: Numbers where the rightmost set bit is 1.
    // - Bucket 2: Numbers where the rightmost set bit is 0.
    int bucket1 = 0, bucket2 = 0;

    // XOR the numbers into their respective buckets:
    // - Numbers where the set bit is 1 will go into bucket1.
    // - Numbers where the set bit is 0 will go into bucket2.
    for (int num : nums) {
        if (num & set_bit) {
            // If the number has the rightmost set bit, XOR it into bucket1.
            bucket1 ^= num;
        } else {
            // If the number does not have the rightmost set bit, XOR it into bucket2.
            bucket2 ^= num;
        }
    }

    // Step 4: At this point, bucket1 contains one unique number (either x or y),
    // and bucket2 contains the other unique number.
    // This is because all other numbers, which appear twice, cancel out within their respective buckets.
    
    // Return the two unique numbers as a pair.
    return {bucket1, bucket2};
}

int main() {
    // Test the function with an example input.
    // In this example, all numbers except 3 and 4 appear twice.
    vector<int> nums = {1, 2, 3, 2, 1, 4};

    // Call the function to find the two unique numbers.
    auto result = findTwoSingleNumbers(nums);

    // Output the result.
    cout << "The two unique numbers are: " << result.first << " and " << result.second << endl;

    return 0;
}


