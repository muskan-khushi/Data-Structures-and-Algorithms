#include <bits/stdc++.h>
using namespace std;

int main(){

    //Declaring an intializing a vector
    //vector<data type> name(size, initialize);
    vector<int> arr(4, 2); //[2, 2, 2, 2]

    //Inserting a value in vector
    vector<int> a;
    a.push_back(4); //[4]
    a.push_back(8); //[4, 8]
    a.push_back(5); //[4, 8, 5, ]
    a.push_back(2); //[4, 8, 5, 2]
    a.push_back(7); //[4, 8, 5, 2, 7, _, _, _]

    vector<int> v = {1, 2, 3, 4, 5};

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i=0; i<n; i++){
        cin >> x[i];
    }

    return 0;
}