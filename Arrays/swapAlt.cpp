#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlt(int arr[], int size)
{
    if (size % 2 == 0)
    {
        for (int i = 0; i < size; i = i + 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    else
    {
        for (int i = 0; i < size - 1; i = i + 2)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{

    int even[6] = {1, 2, 3, 4, 5, 6};
    int odd[5] = {1, 2, 3, 4, 5};

    swapAlt(even, 6);
    printArray(even, 6);

    swapAlt(odd, 5);
    printArray(odd, 5);

    return 0;
}