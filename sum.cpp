#include <iostream>
using namespace std;

float sum(float a, float b)
{
    return a + b;
}

int main()
{
	float a = 5.1;
	float b = 10.1;
	float suma = sum(a, b);
	cout << "la somma tra \n"
		 << a 
		 << "\n"
		 << b
		 << "\nè\n"
		 << "è"
		 << suma << endl;
	return 0;
}