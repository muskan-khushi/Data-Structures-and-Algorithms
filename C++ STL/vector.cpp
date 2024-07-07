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

    //Dynamic memory allocation (at run time) like the one of vectors is always done in heap because heap has large amounts of memory.
    //In case of arrays, static memory allocation is done (at compile time) in stack.

    //Removing values from vector
    v.pop_back(); //removes last value //TC -> O(1)
    v.clear(); //removes all values
    v.erase(v.begin()+2); //removes value at index 2
    //TC -> O(n)
    //let initial v = {1, 2, 3, 4, 5}
    //final v = {1, 2, 4, 5, }

    //Size and Capacity of Vector
     //size is the number of elements in vector
     //capacity is number of elements + empty spaces in vector.

    
    //Front, back, at, empty
    // v = [1, 2, 3, 4]
    cout << v.front(); //1
    cout << v.back(); //4
    v.empty(); //if arr empty, returns 1, else 0
    //at find out yourself

    //Iterator in a vector
    //v = [4,6,8,10]
    v.begin(); //points at 4
    v.end(); //points at the memory block after 10
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }

    //auto a = 10; 
    //auto is used for type inference, allowing the compiler to deduce the type of a variable from its initializer.

    v.rbegin(); //points at 10
    v.rend(); //points at address before 4

   //Alt to print elements in vector
   for (int i=0; i<v.size(); i++){
    cout << v[i] << " ";
   }

   //Sorting a vector
   sort(v.begin(), v.end()); //sorts a vector in increasing order
   sort(v.begin(), v.end(), greater<int>());
    
   //Search

    return 0;
}