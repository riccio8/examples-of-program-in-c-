#include <iostream>

// Function to display a message
void displayMessage() {
    std::cout << "Hello from a function pointer!" << std::endl;
}

int main() {
    void (*funcPtr)() = displayMessage; // Declare a function pointer and assign the function
    funcPtr(); // Call the function using the pointer

    return 0;
}
