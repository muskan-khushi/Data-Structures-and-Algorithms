#include <bits/stdc++.h>
using namespace std;

bool search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
return false;
}

int main() {

    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};

    cout << "Enter the element to be searched: ";
    int key;
    cin >> key;

    //whether 1 is present in it or not
    bool found = search(arr, 10, key);

    if (found) {
        cout << "Key is present is array." << endl;
    }
    else {
        cout << "Key is not present." << endl;
    }

    return 0;
}