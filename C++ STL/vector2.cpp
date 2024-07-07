#include <bits/stdc++.h>
using namespace std;

int main()
{

        //Create vector
        vector<int> v;
        vector<int> v1(5, 1);

        //Size and capacity
        v.push_back(2);
        v.push_back(3);
        v.push_back(10);
        cout << "Size of v: " << v.size() << endl; //3
        cout << "Capacity of v: "<< v.capacity() << endl; //4

        //Update Value
        v[1] = 5;

        cout << "Size of v1: " << v1.size() << endl; //5
        cout << "Capacity of v1: "<< v1.capacity() << endl; //5
        v1.push_back(8);
        cout << "Size of v1: " << v1.size() << endl; //6
        cout << "Capacity of v1: "<< v1.capacity() << endl; //10

        vector<int> v3 = {1,2, 3, 4, 5};
        cout << v3.size() << endl;

    //Delete value from vector
    vector<int> vNew;
    vNew.push_back(4);
    vNew.push_back(41);
    vNew.push_back(14);
    vNew.push_back(42);
    vNew.push_back(84);
    vNew.pop_back();
    cout << "Size of vNew: " << vNew.size() << endl;
    cout << "Capacity of vNew: " << vNew.capacity() << endl;

    vNew.erase(vNew.begin() + 1); // erases 41
    cout << "Size of vNew: " << vNew.size() << endl;
    cout << "Capacity of vNew: " << vNew.capacity() << endl;
    for (int i = 0; i < vNew.size(); i++)
    {
        cout << vNew[i] << " ";
    }

    vNew.insert(vNew.begin() + 1, 50); // inserts 50 at index 1
    cout << endl;
    for (int i = 0; i < vNew.size(); i++)
    {
        cout << vNew[i] << " ";
    }

    vNew[1] = 37;
    for (int i = 0; i < vNew.size(); i++)
    {
        cout << vNew[i] << " ";
    }

    cout << endl;
    vNew.clear(); //removes all the element
    cout << "Size of vNew: " << vNew.size() << endl; //0
    cout << "Capacity of vNew: " << vNew.capacity() << endl; //8

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(12);
    arr.push_back(21);
    arr.push_back(122);
    cout << arr[0] << endl;
    cout << arr.front() << endl;

    cout << arr.size()-1 << endl;
    cout << arr.back() << endl;

    vector<int> a;
    //copy value of one vector to another
    a = arr;
    cout << a.size() << endl;
    for(auto it=arr.begin(); it!= arr.end(); it++){
        cout << *it <<" ";
    }
    cout << endl;
    for (auto i: arr){
        cout << i << " ";
    }

    vector<int> ans;
    ans.push_back(5);
    ans.push_back(235);
    ans.push_back(15);
    ans.push_back(54);
    ans.push_back(125);

    // sort in increasing order
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    // sort in decreasing order
    // sort(ans.begin(), ans.end(), greater<int>());
    //  sort(ans.rbegin(), ans.rend());
    //  for (auto i: ans){
    //      cout << i << " ";
    //  }
    //  cout << endl;

    // Search in Binary Search
    cout << binary_search(ans.begin(), ans.end(), 54) << endl; // 1

    cout << find(ans.begin(), ans.end(), 54)-ans.begin() << endl; //2

    return 0;
}