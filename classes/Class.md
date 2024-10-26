
### Classes README.md

### Detailed Explanation of Classes

#### What Are Classes?

Classes are blueprints for creating objects in C++. They encapsulate data for the object and methods to manipulate that data. This encapsulation helps in organizing code and implementing Object-Oriented Programming (OOP) principles, such as encapsulation, inheritance, and polymorphism.

#### Key Features of Classes

1. **Encapsulation**: Classes allow you to bundle data (attributes) and functions (methods) that operate on the data into a single unit. This restricts direct access to some of the object’s components, which is a means of preventing accidental interference and misuse of the methods and data.

2. **Abstraction**: Classes help in hiding the complex implementation details while exposing only the necessary parts of an object. Users interact with objects through well-defined interfaces (methods).

3. **Inheritance**: Classes can inherit properties and methods from other classes, allowing for a hierarchical classification. This promotes code reusability.

4. **Polymorphism**: Classes support polymorphism, where a single interface can represent different underlying data types. It allows methods to do different things based on the object it is acting upon.

#### Structure of a Class

Here is a basic structure of a class in C++:

```cpp
class ClassName {
private:
    // Private attributes (data members)
    int attribute;

public:
    // Constructor
    ClassName(int value) : attribute(value) {}

    // Public method to access private attribute
    void display() {
        std::cout << "Value: " << attribute << std::endl;
    }
};
```

### Example of Classes in C++

#### Example of a Class with Access Modifiers

```cpp
#include <iostream>

class BankAccount {
private:
    std::string accountNumber; // Private attribute
    double balance;             // Private attribute

public:
    // Constructor
    BankAccount(std::string number, double initialBalance) 
        : accountNumber(number), balance(initialBalance) {}

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << std::endl;
        } else {
            std::cout << "Invalid deposit amount!" << std::endl;
        }
    }

    // Public method to check balance
    void checkBalance() {
        std::cout << "Current balance: $" << balance << std::endl;
    }
};

int main() {
    BankAccount myAccount("123456789", 1000.00); // Create a new account
    myAccount.deposit(200); // Deposit money
    myAccount.checkBalance(); // Check balance

    return 0;
}
```
# BankAccount.cpp

This program demonstrates the use of a class in C++. It defines a `BankAccount` class with private attributes and public methods to manipulate them, illustrating encapsulation.

## How to Run

1. Compile the program using:
   ```bash
   g++ BankAccount.cpp -o BankAccount
   ```
2. Run the executable:
   ```bash
   ./BankAccount
   ```


### Example of Inheritance

```cpp
#include <iostream>

class Vehicle { // Base class
public:
    void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

class Car : public Vehicle { // Derived class
public:
    void honk() {
        std::cout << "Car honks!" << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.start(); // Calls base class method
    myCar.honk();  // Calls derived class method

    return 0;
}
```


## Contents

- **SimpleClass.cpp**: Demonstrates a basic class with attributes and methods.
- **InheritanceExample.cpp**: Shows how to implement inheritance in C++.
- **PolymorphismExample.cpp**: Illustrates polymorphism through virtual functions.

### Getting Started

To run these examples, use a C++ compiler like `g++` and follow the provided instructions in each file. Understanding classes will enable you to design and implement complex systems effectively.

## Example Programs

1. **SimpleClass.cpp**
2. **InheritanceExample.cpp**
3. **PolymorphismExample.cpp**
