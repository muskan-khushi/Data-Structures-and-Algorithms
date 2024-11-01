#include <bits/stdc++.h>
using namespace std;

// Function to find XOR of all numbers from 1 to n
int XORallNumbers(int n) {
    // The XOR of numbers from 1 to n follows a repeating pattern every 4 numbers:
    // If n % 4 == 0: XOR(1 to n) = n (because the pattern repeats with XOR equal to n)
    // If n % 4 == 1: XOR(1 to n) = 1 (because n=1 results in XOR being 1)
    // If n % 4 == 2: XOR(1 to n) = n + 1 (because adding the next number results in n+1)
    // If n % 4 == 3: XOR(1 to n) = 0 (because XOR from 1 to 3 results in 0, pattern repeats)
    
    if (n % 4 == 1) return 1;         // Case where n % 4 == 1, XOR result is 1
    if (n % 4 == 2) return n + 1;     // Case where n % 4 == 2, XOR result is n + 1
    if (n % 4 == 3) return 0;         // Case where n % 4 == 3, XOR result is 0
    else return n;                    // Case where n % 4 == 0, XOR result is n
}

// Function to find XOR of numbers from l to r
int XORfromLtoR(int l, int r) {
    // To find XOR of numbers from l to r, we can utilize the XOR from 1 to r and XOR from 1 to l-1:
    // XOR(l to r) = XOR(1 to r) ^ XOR(1 to l-1)
    // The logic is that XOR from 1 to l-1 cancels out the part before l, leaving XOR(l to r)
    
    return XORallNumbers(r) ^ XORallNumbers(l - 1);
}

int main() {
    int n, l, r;

    // Example 1: XOR of all numbers from 1 to n
    cout << "Enter the value of n: ";
    cin >> n;
    // Call the function to calculate XOR of all numbers from 1 to n
    cout << "XOR of all numbers from 1 to " << n << " is: " << XORallNumbers(n) << endl;

    // Example 2: XOR of numbers from l to r
    cout << "Enter the range l and r: ";
    cin >> l >> r;
    // Call the function to calculate XOR from l to r
    cout << "XOR of numbers from " << l << " to " << r << " is: " << XORfromLtoR(l, r) << endl;

    return 0;
}
