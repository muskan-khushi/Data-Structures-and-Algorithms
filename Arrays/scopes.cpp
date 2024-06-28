#include <iostream>
using namespace std;

void update(int arr[], int n)
{

    cout << "inside the function" << endl;
    
    arr[0] = 120;

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "going back to main function" << endl;
}

int main()
{

    int arr[3] = {1, 2, 3};
    update(arr, 3);

    // printing the array
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //array also gets changed in the main function because in arrays, always addresses are passed and hence, pass by reference is used.

    //ques - find sum of array given an input array and its size

    return 0;
}