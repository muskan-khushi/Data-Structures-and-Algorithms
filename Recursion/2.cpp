#include <bits/stdc++.h>
using namespace std;

//print name n times
void printName(int i, int n){
if (i > n) return;
cout << "Rohit" << endl;
printName(i+1, n);
}
//TC -> O(N) n functions called
//SC -> O(N) stack space


//print linearly from 1 to n
void printNumber(int i, int n)
{
    if (i > n) return;
    cout << i << endl;
    printNumber(i+1, n);
}


//print linearly from n to 1
void reversePrint (int n){
    if (n == 0) return;
    cout << n << endl;
    n--;
    reversePrint(n);
}


//print linearly from 1 to n by BackTracking
//Structure the recursive function to reach the base case first, then perform the printing action during the backtracking phase
void printNo (int n){
    if (n<1) return;
    printNo(n-1);
    cout << n << endl;
}

//print linearly from n to 1 using backtracking
//print number first then make the recursive call
void printReverse(int n) {
    // Base case
    if (n == 0) {
        return;
    }
    // Print the current number
    cout << n << endl;
    // Recursive call
    printReverse(n - 1);
}



int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    //printName(1, n);
    //printNumber(1, n);
    //reversePrint(n);
    //printNo(n);
    //printReverse(n);
    return 0;
}