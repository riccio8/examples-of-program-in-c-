#include <iostream>
using namespace std;

int main() {
    int numero;

    do {
        cout << "Inserisci un numero: ";
        cin >> numero;

        if (numero % 7 == 0)
            break;
    } while (true);

    cout << "Il numero inserito è divisibile per 7." << endl;

    return 0;
}