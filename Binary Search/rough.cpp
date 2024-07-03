//Rewriting the Binary Search Code

#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = start + (end - start)/2;

    while (start <= end) {

        if(arr[mid] == key){
            return mid;
        }

        else 
        { 
            if (arr[mid] > key) {
              end = mid - 1;
        }
           else {
            start = mid + 1;
           }
        
        mid = start + (end - start)/2;
        }
    }
    return -1;
}

int main() {

    int arr[5] = {3,4,5,6,7};
    int largest = largestElement(arr, 5, 7);
    cout << largest;

    return 0;
}