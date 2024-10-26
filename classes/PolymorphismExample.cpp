#include <iostream>

class Animal { // Base class
public:
    virtual void sound() { // Virtual function
        std::cout << "Some sound..." << std::endl;
    }
};

class Dog : public Animal { // Derived class
public:
    void sound() override { // Override base class method
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal { // Another derived class
public:
    void sound() override { // Override base class method
        std::cout << "Meow!" << std::endl;
    }
};

void makeSound(Animal* animal) {
    animal->sound(); // Call the sound method
}

int main() {
    Dog dog;
    Cat cat;

    makeSound(&dog); // Calls Dog's sound method
    makeSound(&cat); // Calls Cat's sound method

    return 0;
}
