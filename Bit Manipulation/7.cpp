//Divide two integers without using multiplication and division operators

#include <bits/stdc++.h>
using namespace std;

// Function to divide two integers without using multiplication, division, or modulus operators
int divide(int dividend, int divisor) {
    // Handle special cases where overflow might occur
    if (dividend == INT_MIN && divisor == -1) {
        // This case results in an overflow (because -INT_MIN > INT_MAX), so return INT_MAX
        return INT_MAX;
    }
    
    // Determine the sign of the result:
    // If dividend and divisor have the same sign, the result will be positive. Otherwise, it will be negative.
    int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

    // Convert both dividend and divisor to positive values (using long to handle edge cases)
    long long absDividend = labs(dividend);
    long long absDivisor = labs(divisor);
    
    // Initialize the result
    int result = 0;

    // Subtract divisor from dividend iteratively while keeping track of how many times the divisor fits
    // This is equivalent to performing the division using bit manipulation to speed up the process.
    while (absDividend >= absDivisor) {
        long long tempDivisor = absDivisor;
        long long multiple = 1;

        // Try to double the divisor as much as possible without exceeding the dividend.
        // By doubling, we are able to subtract large chunks in each iteration (like binary search).
        while (absDividend >= (tempDivisor << 1)) {
            tempDivisor <<= 1;   // Double the divisor
            multiple <<= 1;      // Double the multiple
        }

        // Subtract the largest possible chunk from the dividend
        absDividend -= tempDivisor;
        // Add the corresponding multiple to the result
        result += multiple;
    }

    // Apply the sign to the result
    return sign * result;
}

int main() {
    int dividend, divisor;
    
    // Input the dividend and divisor from the user
    cout << "Enter the dividend: ";
    cin >> dividend;
    
    cout << "Enter the divisor: ";
    cin >> divisor;
    
    // Call the divide function and output the result
    cout << "Result of division: " << divide(dividend, divisor) << endl;

    return 0;
}
