//condition -> element should be in monotonic function //sorted

//find mid element
//compare mid with key
// if ==, return index
// if != path decide
//repeat

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int size, int key) {

int start = 0;
int end = size - 1;

int mid = (start + end)/2;

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

mid = (start + end)/2;

}
return -1;
}

int main() {

    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 12);
    cout <<"index of 12 is: " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);
    cout << "Index of 14 is: " << oddIndex << endl;

    return 0;
}