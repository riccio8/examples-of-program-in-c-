#include <iostream>
using namespace std;

int main() {
    int number;

    do {
        cout << "Insert a number: \n";
        cin >> number;

        if (number % 7 == 0)
            break;
    } while (true);

    cout << "Number is divisible by 7." << endl;

    return 0;
}
