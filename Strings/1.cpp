#include <bits/stdc++.h> // Including all standard libraries
using namespace std; // Using standard namespace

int main() {
    // Initializing a character array with individual characters
    // char arr[] = {'A','P','P','L','E'};
    // cout << arr; // Prints the array as a string

    // Declaring a character array of size 20
    char arr[20];
    // Reading input into the character array
    // cin >> arr;
    // Modifying the character at index 2 to be a null character
    // arr[2] = '\0';
    // Printing the array, which will stop at the null character
    // cout << arr;

    // Note: A null character is automatically stored at the end of the string
    // This tells the system where the string ends

    // The last space in a char array is always reserved for the null character.
    // If we declare a char array of 10 elements and try to put 10 characters in it, it will throw an error.

    // For example, if the string we entered is "RO\0HIT" only "RO" will get printed because it will stop printing after the null character.

    // Declaring a string (works similarly to a char array but with dynamic memory allocation)
    string s;
    // To give inputs with spaces in strings we need to replace cin with:
    // getline(cin, s);
    // cout << s;

    // Print the size of the string
    cout << s.size() << endl;

    // To concatenate (join) two strings
    string s1 = "rohit";
    string s2 = "mohit";
    // Concatenate s1 and s2
    string s3 = s1 + s2; // Result: "rohitmohit"
    // Append a character to s1
    s1.push_back('p'); // Result: "rohitp"
    // Remove the last character from s1
    s1.pop_back(); // Result: "rohit"

    // Using escape characters
    string s4 = "we are \"good\""; // Result: we are "good"
    string s5 = "\0"; // Prints a blank character because it is a null character

    return 0; // Return 0 to indicate successful execution
}
