#include <iostream>

int main() {
    int var = 42;             // Declare an integer variable
    int* ptr = &var;         // Declare a pointer and assign the address of var

    std::cout << "Value of var: " << var << std::endl;                // Output the value of var
    std::cout << "Address of var: " << &var << std::endl;             // Output the address of var
    std::cout << "Value of ptr: " << ptr << std::endl;                // Output the address stored in ptr
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;       // Output the value pointed to by ptr

    return 0;
}
