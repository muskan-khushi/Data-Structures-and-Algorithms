#include <bits/stdc++.h>
using namespace std;

//Multiple Recursion Calls

// Return nth Fibonacci Number
int fibonacci(int n){
    if (n<=1) return n;
    // int last = fibonacci(n-1);
    // int secLast = fibonacci(n-2);
    // return last + secLast;
    return fibonacci(n-1) + fibonacci(n-2);
    //fibonacci(n-1) gets executed first and only after its completion f(n-2) gets executed.
}
//TC => O(2^n) for every n, we are have 2 recursion calls (from recursion tree)

//Recursion Tree

int main(){
     int n = 4;
     cout << fibonacci(n);
    return 0;
}