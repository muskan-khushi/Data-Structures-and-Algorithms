#include <bits/stdc++.h>
using namespace std;

// **Binary Conversion and Bitwise Operations in C++**

/* 
This program contains functions to convert an integer to its binary representation 
and a binary string to its decimal equivalent. It also includes comments for 
understanding the concepts of 1's complement, 2's complement, and basic bitwise operators. 
*/

// Time Complexity -> O(log2(N))
// Space Complexity -> O(log2(N))
// Function to convert an integer to its binary representation
string convert2Binary(int n) {
    string res = ""; // To store the binary result as a string

    // Loop until n becomes 1 (since the last bit for any number is either 1 or 0)
    while (n != 1) {
        // Check if the number is odd (bit is 1) or even (bit is 0)
        if (n % 2 == 1) {
            res += '1';  // Append '1' for odd numbers
        }
        else {
            res += '0';  // Append '0' for even numbers
        }
        n /= 2;  // Divide the number by 2 (right shift in binary)
    }

    // After the loop, the result will be in reverse order, so we reverse the string
    reverse(res.begin(), res.end());

    // Return the binary representation
    return res;
}

/* 
Time Complexity -> O(len), where len is the length of the binary string
Space Complexity -> O(1)
Function to convert a binary string to a decimal number
*/
int convert2Decimal(string x) {
    int decimal = 0; // This will store the final decimal number
    int base = 1;    // Represents the current power of 2 (2^0 initially)

    // Loop through the string from the rightmost bit (least significant bit)
    for (int i = x.size() - 1; i >= 0; i--) {
        if (x[i] == '1') {
            decimal += base;  // If the bit is 1, add the current base (2^position) to the decimal result
        }
        base *= 2;  // Move to the next power of 2 (2^1, 2^2, ...)
    }

    // Return the final decimal result
    return decimal;
}

// **Understanding 1's and 2's Complement in Binary Arithmetic**
/*
1. **1's Complement**: Flip all the bits in the binary representation of a number.
   Example: 1's complement of 1010 is 0101.

2. **2's Complement**: Add 1 to the 1's complement of a number. This is used to represent negative numbers.
   Example: 2's complement of 1010 (which is 0101) is 0110.

   In computer systems, negative numbers are usually stored using 2's complement.

   **Note**: The most significant bit (MSB) in 2's complement represents the sign (0 for positive, 1 for negative).
*/

// **Basic Bitwise Operators**
/*
1. **AND Operator (`&`)**: 
   - Takes two bits, returns 1 if both bits are 1, otherwise returns 0.
   Example: 1010 & 1100 = 1000

2. **OR Operator (`|`)**:
   - Takes two bits, returns 1 if at least one bit is 1, otherwise returns 0.
   Example: 1010 | 1100 = 1110

3. **XOR Operator (`^`)**:
   - Takes two bits, returns 1 if one bit is 1 and the other is 0, otherwise returns 0.
   Example: 1010 ^ 1100 = 0110

4. **NOT Operator (`~`)**:
   - Inverts all the bits (flips 0s to 1s and vice versa).
   Example: ~1010 = 0101 (in 1's complement)

5. **Right Shift (`>>`)**:
   - Shifts the bits to the right by a specified number of positions, filling the left with 0s.
   Example: 1010 >> 1 = 0101

6. **Left Shift (`<<`)**:
   - Shifts the bits to the left by a specified number of positions, filling the right with 0s.
   Example: 1010 << 1 = 10100
*/

// **Maximum and Minimum Values for an Integer**
/*
- The largest value that can be stored in an integer (typically 4 bytes = 32 bits) 
  is calculated as:
  2^31 - 1 = 2147483647 (this is `INT_MAX`).

- The smallest value (negative) that can be stored is:
  -2^31 = -2147483648 (this is `INT_MIN`).
*/

// **Main Function**
int main() {

    // Test cases or further implementation can be added here
    return 0;
}
