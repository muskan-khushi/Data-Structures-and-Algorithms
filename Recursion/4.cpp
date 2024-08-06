#include <bits/stdc++.h>
using namespace std;

//Reverse an array using recursion
//using single pointer
void reverseRec(int i, int arr[], int n){
  if (i>=n/2) return;
  swap(arr[i],arr[n-i-1]);
  reverseRec(i+1, arr, n);
}

//Check if a given string is palindrome
//using single pointer again
bool palindrome(int i, string &s){
     if (i>= s.size()/2) return true;
     if (s[i] != s[s.size()-i-1]) return false;
     palindrome(i+1, s);
}

int main(){
int n;
cin >> n;
int arr[n];
for (int i=0; i<n; i++){
    cin >> arr[i];
}
reverseRec(0, arr, n);
for (int i=0; i<n; i++){
    cout << arr[i] << " ";
}

string s = "madam";
cout << palindrome(0, s);
    return 0;
}