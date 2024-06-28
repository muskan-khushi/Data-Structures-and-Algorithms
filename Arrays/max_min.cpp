#include <bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int size){
    int largest = arr[0];
    for (int i = 0; i < size; i++){
      if (arr[i] > largest){
        largest = arr[i];
    }
  }
  return largest;
}

int smallestElement(int arr[], int size){
    int smallest = arr[0];
    for (int i = 0; i < size; i++){
      if (arr[i] < smallest){
        smallest = arr[i];
    }
  }
  return smallest;
}

int main() {

int size;
cin >> size;

int num[size];

//taking array as input
for (int i = 0; i< size; i++){
    cin >> num[i];
}

int largest = largestElement(num, 5);
int smallest = smallestElement(num, 5);

cout << "Largest and smallest element of an array are " << largest << " and " << smallest << " respectively." << endl;

    return 0;
}