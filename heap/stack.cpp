    #include <iostream>
    using namespace std;

    void stackExample() {
        int a = 10; // a is stored in the stack
        cout << "Stack value: " << a << endl; // Prints 10
    } // a is gone when the function exits

    int main() {
        stackExample();
        // a is not accessible here
        return 0;
    }
