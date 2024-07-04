#include <bits/stdc++.h>
using namespace std;

//Takes an element and places it in its correct position

//Given array -> 14, 9, 15, 12, 6, 8, 13

void insertionSort(int arr[], int n){
for (int i=0; i<=n-1; i++){
    int j=i;
    while(j>0 && arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;

        j--;
        cout << "runs\n";
    }
}
}

//Worst Case/ Average Case Time Complexity -> O(n^2)
//Best Case Time Complexity -> O(n)

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    insertionSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}