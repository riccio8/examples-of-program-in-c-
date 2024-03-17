#include <iostream>

int main() 
{
	int a = 1;
	int b = 2;
	int stand = a;
	a = b;
	b = stand;
	std::cout << a;
    return 0;
}