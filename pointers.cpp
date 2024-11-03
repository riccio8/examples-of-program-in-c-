#include <iostream>

using namespace std; 

int main()
{
	int prova = 5;
	int *Pprova2 = &prova;
	int *Pcaso = nullptr;
	
	
	cout << prova << endl;
	cout << &prova <<endl;
	cout << Pprova2 << endl;
	cout << Pcaso << endl;
	
	return 0;
}
