#include <bits/stdc++.h>
using namespace std;

//**** Swap 2 numbers without using an extra variable ****
// This uses the XOR bitwise operator to swap two numbers without the need for an extra variable.
void swapNumbers(int a, int b){
    cout << "Before swapping: " << endl;
    cout << "First number is: " << a << endl;
    cout << "Second number is: " << b << endl;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "After swapping: " << endl;
    cout << "First number is: " << a << endl;
    cout << "Second number is: " << b << endl;
}

//**** Check if the ith bit is set (1) or not (0) ****
// Method 1: Using left shift operator (<<)
bool checkSetBit1(int num, int i){
    return (num & (1 << i)) != 0;
}

// Method 2: Using right shift operator (>>)
bool checkSetBit2(int num, int i){
    return ((num >> i) & 1) != 0;
}

//**** Set the ith bit (make it 1) ****
int setBit(int num, int i){
    return num | (1 << i);
}

//**** Clear the ith bit (make it 0) ****
int clearBit(int num, int i){
    return num & ~(1 << i);
}

//**** Toggle the ith bit (flip between 1 and 0) ****
int toggleBit(int num, int i){
    return num ^ (1 << i);
}

//**** Removing the last set bit (rightmost 1 bit) ****
void removeLastSetBit(int num){
    num = num & (num - 1);
    cout << "After removing the last set bit, number is: " << num << endl;
}

//**** Check if a number is a power of 2 ****
bool checkPow2(int num){
    return (num > 0 && (num & (num - 1)) == 0);
}

//**** Counting the number of set bits (1-bits) in a number ****
// Approach 1: Divide the number by 2 repeatedly
int countSetBits(int num){
    int cnt = 0;
    while (num > 0){
        if (num % 2 == 1) cnt++;
        num /= 2;
    }
    return cnt;
}

// Optimized approach for counting set bits using bitwise operations
int countSetBitsOptimized(int num){
    int cnt = 0;
    while (num > 0){
        num = num & (num - 1);
        cnt++;
    }
    return cnt;
}

int main(){
    //**** Demonstrate swapNumbers function ****
    int a = 5, b = 10;
    swapNumbers(a, b);
    cout << endl;

    //**** Demonstrate checkSetBit1 and checkSetBit2 functions ****
    int num = 29; // Binary: 11101
    int i = 3;
    cout << "Using left shift to check if " << i << "th bit is set in " << num << ": "
         << (checkSetBit1(num, i) ? "Yes" : "No") << endl;
    cout << "Using right shift to check if " << i << "th bit is set in " << num << ": "
         << (checkSetBit2(num, i) ? "Yes" : "No") << endl;
    cout << endl;

    //**** Demonstrate setBit function ****
    num = 29;  // Binary: 11101
    i = 1;     // Set the 1st bit (which is already set, but demo purpose)
    cout << "Before setting the " << i << "th bit: " << num << endl;
    num = setBit(num, i);
    cout << "After setting the " << i << "th bit: " << num << endl;
    cout << endl;

    //**** Demonstrate clearBit function ****
    num = 29;  // Binary: 11101
    i = 2;     // Clear the 2nd bit
    cout << "Before clearing the " << i << "th bit: " << num << endl;
    num = clearBit(num, i);
    cout << "After clearing the " << i << "th bit: " << num << endl;
    cout << endl;

    //**** Demonstrate toggleBit function ****
    num = 29;  // Binary: 11101
    i = 0;     // Toggle the 0th bit (from 1 to 0)
    cout << "Before toggling the " << i << "th bit: " << num << endl;
    num = toggleBit(num, i);
    cout << "After toggling the " << i << "th bit: " << num << endl;
    cout << endl;

    //**** Demonstrate removeLastSetBit function ****
    num = 84;  // Binary: 1010100
    cout << "Before removing the last set bit: " << num << endl;
    removeLastSetBit(num);
    cout << endl;

    //**** Demonstrate checkPow2 function ****
    num = 32;  // Binary: 100000
    cout << num << " is a power of 2: " << (checkPow2(num) ? "Yes" : "No") << endl;
    num = 18;  // Binary: 10010
    cout << num << " is a power of 2: " << (checkPow2(num) ? "Yes" : "No") << endl;
    cout << endl;

    //**** Demonstrate countSetBits and countSetBitsOptimized functions ****
    num = 29;  // Binary: 11101
    cout << "Number of set bits in " << num << " using basic approach: " << countSetBits(num) << endl;
    cout << "Number of set bits in " << num << " using optimized approach: " << countSetBitsOptimized(num) << endl;

    return 0;
}



