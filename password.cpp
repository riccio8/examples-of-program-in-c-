#include <iostream>
#include <random>
using namespace std;

string gen(int lun) {
    string password;

string caratteri = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz"
                    "0123456789"
                    "!@#$%^&*()_+=-"
                    "$€£¥??"
                    "??????????"
                    "±÷×==?˜8??"
                    "????????????????????????????????????????????????????????????????";


    random_device rd;
    mt19937 generatore(rd());
    uniform_int_distribution<> distribuzione(0, caratteri.size() - 1);

    for (int i = 0; i < lun; ++i) {
        char carattereCasuale = caratteri[distribuzione(generatore)];
        password += carattereCasuale;
    }

    cout << "Password generata: " << password << endl;
    return password; 
}

int main() {
	while (true)
	{
	   int lunghezza;
	    cout << "Inserisci la lunghezza della password: ";
	    cin >> lunghezza;
	    gen(lunghezza); 
	    return 0;
	}

}
