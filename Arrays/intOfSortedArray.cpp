// Problem statement
// You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

// Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

// Note :
// 1. The length of each array is greater than zero.
// 2. Both the arrays are sorted in non-decreasing order.
// 3. The output should be in the order of elements that occur in the original arrays.
// 4. If there is no intersection present then return an empty array.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints :
// 1 <= T <= 100
// 1 <= N, M <= 10^4
// 0 <= A[i] <= 10^5
// 0 <= B[i] <= 10^5

// Time Limit: 1 sec




#include <bits/stdc++.h>
using namespace std;

//TLE ERROR!!
// vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
// {
// 	// Write your code here.
// 	vector<int> ans;

// 	for (int i=0; i<n; i++){
// 		int element = arr1[i];

// 		for (int j=0; j<m; j++){

// 			if (element < arr2[j])
// 				break;


// 			if (element == arr2[j]){
//             ans.push_back(element);
// 			arr2[j] = -18227;
// 			break;
// 			}
// 		}
// 	}
// 	return ans;
// }




//MORE OPTIMIZED SOLUTION
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	int i = 0, j = 0;

	vector<int> ans;

	while (i<n && j<m){

		if (arr1[i] == arr2[j]){
           ans.push_back(arr1[i]);
		   i++;
		   j++;
		}

		else if (arr1[i] < arr2[j]){
			i++;
		}

		else {
             j++;
		}
		
	}
	return ans;
}



int main()
{
    return 0;
}