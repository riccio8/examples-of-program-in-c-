#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // An array of integers
    int* ptr = arr;                  // Pointer to the first element of the array

    std::cout << "Array elements using pointer arithmetic:" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i << ": " << *(ptr + i) << std::endl; // Accessing elements using pointer arithmetic
    }

    return 0;
}
