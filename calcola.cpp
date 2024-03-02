#include <iostream>

using namespace std;

int main() {
    char operatore;
    double numero1, numero2;

    while (true) {
        cout << "Inserisci l'operazione (+, -, *, /) oppure 'q' per uscire: ";
        cin >> operatore;

        if (operatore == 'q') 
		{
            cout << "Arrivederci!";
            break;
		}
		
		
 		cout << "Inserisci il primo numero: ";
        cin >> numero1;

        cout << "Inserisci il secondo numero: ";
        cin >> numero2;
		
		switch (operatore)
		{
			case '+':
				cout << "Risultato = " << numero1 + numero2 << endl;
			case '-':
				cout << "Risultato = " << numero1 - numero2 << endl;
			case '*':
				cout << "Risultato = " << numero1 * numero2 << endl;
			case '/':
				cout << "Risultato = " << numero1 / numero2 << endl;		
		}	
		
		
	}
		return 0;
		
}