// Given that there are N books and M students. Also given are the number of pages in each book in ascending order. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum, with the condition that every student is assigned to read some consecutive books. Print that minimum number of pages.

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector <int> arr, int n, int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for (int i=0; i<n; i++){
        if (pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else {
            studentCount++;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = 0;
            pageSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(vector <int> arr, int n, int m){
    int s = 0;
    int sum = 0;
    
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;

    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(arr, n, m, mid)){
          ans = mid;
          e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main(){

    return 0;
}