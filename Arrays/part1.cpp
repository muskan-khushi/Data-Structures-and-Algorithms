// If we define an array before int main, i.e. in the global scope, it will all be initialised with '0' instead of garbage values.

// Max size of an array is 10^7 if we declare it globally, else 10^6

// Array indexing is from 0 to n-1

// We cannot predict the starting memory address of an array. Therefore, accessing the array by its address is not possible.

#include <bits/stdc++.h>
using namespace std;

// LARGEST ELEMENT IN AN ARRAY

// Brute force solution
// sort the array and access the largest element by the n-1 th index element

// Better Solution

// Optimal Solution
int findLargestElement(int arr[], int n)
{

    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {

        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int arr[] = {2, 5, 1, 3, 0};
    int n = 5;

    int max = findLargestElement(arr, n);
    cout << "Largest element of the array is: " << max << endl;
    return 0;
}
