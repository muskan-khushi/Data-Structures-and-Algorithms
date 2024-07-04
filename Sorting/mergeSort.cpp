#include <bits/stdc++.h>
using namespace std;

//Divide and Merge

//[3, 1, 2, 4, 1, 5, 2, 6, 4]
//[3, 1, 2, 4, 1]  [5, 2, 6, 4]
//[3, 1, 2] [4, 1] 
//[3, 1] [2]
//[3] [1]

//Merge (in sorted manner)
//[1, 3] [2]
//[1, 2, 3] 

void merge(vector <int> &arr, int low, int mid, int high){
    vector<int> temp;
    //[low...mid]
    //[mid+1...high]
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high){
       if (arr[left] <= arr[right]){
           temp.push_back(arr[left]);
           left++;
       }
       else {
           temp.push_back(arr[right]);
           right++;
       }
    }
    while (left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

void mS(vector <int> &arr, int low, int high){
if (low == high) return;
int mid = low + (high-low)/2;
mS(arr, low, mid);
mS(arr, mid+1, high);
merge(arr, low, mid, high);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    mS(arr, 0, n-1);
}

//Worst Case Time Complexity -> O(n * log2(n))
//Space Complexity = O(n)

int main(){

    return 0;
}