#include <iostream>

class Animal { // Base class
public:
    void eat() {
        std::cout << "This animal eats food." << std::endl;
    }
};

class Dog : public Animal { // Derived class
public:
    void bark() {
        std::cout << "Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat(); // Calling base class method
    myDog.bark(); // Calling derived class method

    return 0;
}
