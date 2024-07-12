#include <bits/stdc++.h> // Including all standard libraries
using namespace std; // Using standard namespace

int main() {
    // Initializing a string
    string s = "rohit";

    // Reverse the string
    int start = 0; // Starting index
    int end = s.size() - 1; // Ending index

    // Swap characters from start and end until they meet in the middle
    while(start <= end){
        swap(s[start], s[end]);
        start++;
        end--;
    }

    // Output the reversed string
    cout << "Reversed string is: " << s;
    cout << endl;

    // Calculate the size of the string manually
    int size = 0; // Initialize size counter
    // Increment size counter until null character is found
    while(s[size]!='\0'){
        size++;
    }
    // Output the size of the string
    cout << "Size of string is: " << size << endl;

    // Check if a string is a palindrome
    string s2 = "naman"; // Palindrome string
    start = 0; // Reset starting index
    end = s2.size()-1; // Reset ending index

    // Compare characters from start and end until they meet in the middle
    while(start<=end){
        if(s2[start]!=s2[end]){ // If characters do not match
            cout << "Not a palindrome" << endl;
            return 0; // Exit the program
        }
        start++;
        end--;
    }
    // If loop completes, the string is a palindrome
    cout << "Palindrome" << endl;

    return 0; // Return 0 to indicate successful execution
}
