#include <iostream>
using namespace std;

/*
 * Pointers in C++
 * A pointer is a variable that stores the memory address of another variable.
 * Pointers are powerful tools in C++ and are used in various scenarios like dynamic memory allocation,
 * arrays, functions, and data structures (e.g., linked lists, trees).
 */

/*
 * Reference Operator (&)
 * The reference operator (&) is used to get the memory address of a variable.
 * When you apply the reference operator to a variable, it returns the address where that variable is stored.
 */

/*
 * Dereference Operator (*)
 * The dereference operator (*) is used to access the value stored at the memory address a pointer is holding.
 * When you apply the dereference operator to a pointer, it gives you the value at the memory address the pointer is pointing to.
 */

void referenceAndDereference() {
    int a = 10;          // A simple integer variable
    int* ptr = &a;       // Using the reference operator (&) to store the address of 'a' in 'ptr'

    cout << "Address of a (&a): " << &a << endl;   // Address of variable 'a'
    cout << "Pointer ptr: " << ptr << endl;        // Address stored in the pointer 'ptr'
    cout << "Value at ptr (*ptr): " << *ptr << endl; // Dereferencing 'ptr' to get the value of 'a'

    // Changing the value of 'a' using the pointer
    *ptr = 20;           // Dereferencing the pointer and changing the value it points to
    cout << "New value of a after changing via *ptr: " << a << endl;
}

/*
 * Pointer Arithmetic
 * You can perform arithmetic operations on pointers like addition and subtraction.
 * When you increment a pointer, it points to the next memory location based on the data type size.
 */
void pointerArithmetic() {
    int arr[] = {1, 2, 3, 4, 5};   // An array of integers
    int* ptr = arr;                // Pointer pointing to the first element of the array

    cout << "Pointer Arithmetic:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << "Value at ptr + " << i << ": " << *(ptr + i) << endl; // Accessing array elements using pointer arithmetic
    }
}

/*
 * Pointers and Arrays
 * Pointers and arrays are closely related. The name of an array is actually a pointer to its first element.
 * You can use pointers to traverse an array or access its elements.
 */
void pointersAndArrays() {
    int arr[] = {10, 20, 30, 40, 50};
    int* ptr = arr; // 'arr' is essentially a pointer to the first element of the array

    cout << "Array Elements using Pointers:" << endl;
    for(int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " "; // Accessing elements using the pointer
    }
    cout << endl;
}

/*
 * Pointers to Pointers (Double Pointers)
 * A pointer to a pointer is a variable that stores the address of another pointer.
 * Double pointers are often used in dynamic memory allocation, data structures, and passing pointers by reference.
 */
void doublePointer() {
    int a = 100;
    int* ptr1 = &a;        // Pointer to integer
    int** ptr2 = &ptr1;    // Pointer to a pointer to integer

    // Printing values using double pointer
    cout << "Value of a using ptr1: " << *ptr1 << endl;      // Dereferencing once gives the value of 'a'
    cout << "Value of a using ptr2: " << **ptr2 << endl;     // Dereferencing twice gives the value of 'a'
}

/*
 * Pointers and Functions
 * Pointers can be passed to functions to allow the function to modify the original value of variables.
 * This is particularly useful for returning multiple values from a function.
 */
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pointerFunctions() {
    int num1 = 10, num2 = 20;

    cout << "Before Swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    swap(&num1, &num2); // Passing the addresses of num1 and num2
    cout << "After Swap: num1 = " << num1 << ", num2 = " << num2 << endl;
}

/*
 * Dynamic Memory Allocation
 * Pointers are crucial for dynamic memory allocation in C++.
 * The 'new' keyword is used to allocate memory, and 'delete' is used to free it.
 */
void dynamicMemory() {
    int* ptr = new int;  // Dynamically allocating memory for a single integer
    *ptr = 50;

    cout << "Dynamically allocated integer value: " << *ptr << endl;

    delete ptr; // Free the allocated memory
}

/*
 * Null Pointers
 * A null pointer is a pointer that points to nothing, i.e., it has the value 'nullptr'.
 * It's a good practice to initialize pointers to 'nullptr' to avoid undefined behavior.
 */
void nullPointer() {
    int* ptr = nullptr; // Null pointer

    if (ptr == nullptr) {
        cout << "Pointer is null" << endl;
    } else {
        cout << "Pointer is not null" << endl;
    }
}

int main() {
    referenceAndDereference();
    cout << endl;

    pointerArithmetic();
    cout << endl;

    pointersAndArrays();
    cout << endl;

    doublePointer();
    cout << endl;

    pointerFunctions();
    cout << endl;

    dynamicMemory();
    cout << endl;

    nullPointer();

    return 0;
}
