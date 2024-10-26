#include <iostream>
#include <random>
#include <string>
using namespace std;

string generate(int length) {
    string password;

    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz"
                        "0123456789"
                        "!@#$%^&*()_+=-"
                        "$���??"
                        "??????????"
                        "���==?�8??"
                        "????????????????????????????????????????????????????????????????";

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    for (int i = 0; i < length; ++i) {
        char randomCharacter = characters[distribution(generator)];
        password += randomCharacter;
    }

    cout << "Generated password: " << password << endl;
    return password; 
}

int main() {
    while (true) {
       int length;
       cout << "Enter the password length: ";
       cin >> length;
       generate(length);
    }
    return 0;  // Program will end only if the while loop is exited
}
