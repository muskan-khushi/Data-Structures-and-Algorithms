#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int size){
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {

    int arr[6] = {1, 4, 0, 2, -2, 15};
    int brr[5] = {6, 5, 4, 3, 2};

    reverse(arr, 6);
    reverse(brr, 5);

    printArray(arr, 6);
    printArray(brr, 5);

    return 0;
}

//swap alternate elements
//find unique element in array
//find duplicate element
// array intersection
//pair sum
//triplet sum
//sort 0s and 1s