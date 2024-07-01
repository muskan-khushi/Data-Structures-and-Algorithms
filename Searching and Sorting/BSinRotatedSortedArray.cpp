#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr, int n){

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if (arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s; //or return e;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {

int start = s;
int end = e;

int mid = start + (end-start)/2;

while(start<=end) {
if (arr[mid] == key){
    return mid;
}

if(key > arr[mid]){

    //go to right waala part
    start = mid + 1;
}
else {
    //go to left waala part
    end = mid - 1;
}

mid = start + (end - start)/2;

}
return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.

    int pivot = getPivot(arr, n);

    //BS on second line
    if (k>=arr[pivot] && k<= arr[n-1]){
        return binarySearch(arr, pivot, n-1, k);
    }

    //BS on first line
    else {
        return binarySearch(arr, 0, pivot - 1, k);
    }

}

int main(){
    vector<int> arr{7, 8, 1, 3, 4};

    int ans = search(arr, 5, 3);
    cout << ans;
    }