    #include <iostream>
    using namespace std;

    void heapExample() {
        int* b = new int; // Allocates memory on the heap
        *b = 20; // Store 20 in the allocated space
        cout << "Heap value: " << *b << endl; // Prints 20
        delete b; // Free the memory to avoid leaks
    } // b is gone, but memory is freed before function exits

    int main() {
        heapExample();
        // b is not accessible here, but memory is cleaned up
        return 0;
    }
