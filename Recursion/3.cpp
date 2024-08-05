#include <bits/stdc++.h>
using namespace std;

//Summation of first n numbers

//TC -> O(N)
//SC -> O(N) Stack Space

//Parameterized Way
void sumParameter(int i, int sum){
    if(i<1) {
        cout << sum;
        return;
    }
    sumParameter(i-1, sum+i);
}

//Functional Way
int sumFunction(int n){
    if (n==0) return 0;
    //in case of fact(multiplication), we need to return 1 instead of 0 in the base case.

    return n + sumFunction(n-1);
}

int main(){
    int n;
    cin >> n;
    sumParameter(n, 0);
    int sum = sumFunction(n);
    cout << sum;
    return 0;
}