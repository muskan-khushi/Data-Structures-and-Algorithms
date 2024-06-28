#include <bits/stdc++.h>
using namespace std;

// passing array in functions
void printArray(int arr[], int size)
{
    cout << "printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "printing done" << endl;
}

int main()
{

    // declare
    int number[15];

    // accessing an array
    // cout << "value at 14 index: " << number[14] << endl; //garbage value

    // cout << "value of 20 index: " << number[20] << endl; //garbage value

    // initialising an array
    int secArray[3] = {5, 7, 11};

    // access an element
    // cout << "value at index 2 is: " << secArray[2] << endl;

    int third[15] = {2, 7}; // no error //rest all elements 0

    // print the array
    // printArray(third, 15);

    // initialising all locations with 0
    int fourth[10] = {0};

    // printArray(fourth, 10);

    // initialising all locations with 1
    // FIND A WAY

    // find actual length of array
    int thirdSize = sizeof(third) / sizeof(int);
    // cout << "size of fourth is: " << thirdSize << endl; //15, cannot take out 2 by any way



    char ch[5] = {'a', 'b', 'c', 'r', 'p'};
    //cout << ch[3] << endl;
    //print the array
      cout << "printing the array" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << ch[i] << " ";
    }
    cout << "printing done" << endl;

    double firstDouble[9];
    float firstFloat[8];
    bool firstBool[5];


    cout << "all cool" << endl
         << endl;

    return 0;
}