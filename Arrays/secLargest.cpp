// Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

// Note: The second largest element should not be equal to the largest element.
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int largest = INT_MIN;
        int secLargest = INT_MIN;
        
        for (int i=0; i<arr.size(); i++){
            if (largest < arr[i]){
                secLargest = largest;
                largest = arr[i];
            }
            else if (largest > arr[i] && secLargest < arr[i] ){
                secLargest = arr[i];
            }
        }
        
        if (secLargest == INT_MIN){
            return -1;
        }
        
        return secLargest;
    }
    

};