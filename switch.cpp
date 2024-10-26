#include <iostream>

using namespace std;

int main() {
    char operation;
    double number1, number2;

    while (true) {
        cout << "Enter the operation (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q') {
            cout << "Goodbye!";
            break;
        }

        cout << "Enter the first number: ";
        cin >> number1;

        cout << "Enter the second number: ";
        cin >> number2;

        switch (operation) {
            case '+':
                cout << "Result = " << number1 + number2 << endl;
                break;
            case '-':
                cout << "Result = " << number1 - number2 << endl;
                break;
            case '*':
                cout << "Result = " << number1 * number2 << endl;
                break;
            case '/':
                if (number2 != 0)
                    cout << "Result = " << number1 / number2 << endl;
                else
                    cout << "Error: Division by zero!" << endl;
                break;
            default:
                cout << "Invalid operation!" << endl;
        }
    }
    return 0;
}
