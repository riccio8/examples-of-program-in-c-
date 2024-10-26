#include <iostream>
#include <string>

class Dog {
public:
    std::string name;   // Attribute

    Dog(std::string n) : name(n) {} // Constructor

    void bark() { // Method
        std::cout << name << " says Woof!" << std::endl;
    }
};

int main() {
    Dog myDog("Buddy"); // Create an object of Dog
    myDog.bark(); // Call the bark method

    return 0;
}
