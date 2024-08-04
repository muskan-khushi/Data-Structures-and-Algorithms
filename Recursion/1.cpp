#include <iostream>
using namespace std;

// Recursion -> When a function calls itself until a specified condition is met

// Infinite Recursion -> causes stack overflow (all functions waiting to be entirely executed in stack)

int myCount = 0;
void print() {
    // Base Case
    if (myCount == 3) {
        return;
    }
    cout << myCount << endl;
    myCount++;
    print();
}

int main() {
    print();
    return 0;
}
