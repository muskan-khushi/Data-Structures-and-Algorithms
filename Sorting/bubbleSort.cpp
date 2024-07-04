#include <bits/stdc++.h>
using namespace std;

//pushes the maximum to the last by adjacent swapping

//given array -> 13, 46, 24, 52, 20, 9
//13, 46, 24, 52, 20, 9
//13, 24, 46, 52, 20, 9
//13, 24, 46, 20, 52, 9
//13, 24, 46, 20, 9, 52

//after one complete round of adjacent swaps, the max element is at the last

//step-2 perform the same algorithm again
//13, 24, 20, 46, 9, 52
//13, 24, 20, 9, 46, 52

//step-3 (last 3 elements sorted)
//13, 20, 24, 9, 46, 52
//13, 20, 9, 24, 46, 52

//step-4 (last 4 elements sorted)
//13, 9, 20, 24, 46, 52

//step-5
//9, 13, 20, 24, 46, 52

void bubbleSort(int arr[], int n){
    for (int i= n-1; i>=0; i--){
        int didSwap = 0;
        for (int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
               // swap(arr[j],arr[j+1]);
               int temp = arr[j+1];
               arr[j+1] = arr[j];
               arr[j] = temp;
               didSwap = 1;
            }
        }
        if (didSwap == 0){
            break;
            //if there is no swapping in the first round means the array is already sorted and there is no need to go for other rounds, hence we break from the loop to get the best case TC.
        }
        cout << "runs\n";
    }
}

//Time Complexity = O(n^2) Worst Complexity/Avg Complexity
//Best Case TC = O(n)


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}