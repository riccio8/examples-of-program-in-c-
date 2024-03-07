// Imade this script because i want to do practice in reverse engeeniring, using a toll preinstalled in kali linux named radare2.
// I also made a very simple repository here on github (here's the link: https://github.com/riccio8/assembly-for-x86/tree/main) where u can find in the file named "radare2" the instructions for a very simple disassemblation
// in that file, i didn't wrote a lot of things, like the cross-check that u can do with the command axt. I didn't do that because before do that, u need to understand the assembly instructions, how registrers work, the stack, buffer size and a lot of other things
// so, i do this script because i'll analze the executable file and try to find the information
// In the future i'll write a script that, using a library like boost/asio, u will have a server script tunning on a machine and the client script running from the other machine and with r2 (radare2) i will try to find the username and the password
// that's all


#include <iostream>

using namespace std;

string username = "Thomas";
string password = "Turbato";
string tried_username;
string tried_password;


int main()
{
	cout << "Write an username: " << endl;
	cin >> tried_username;
	
	
	if (tried_username == username)
	{
		cout << "The username is correct, now write the password: " << endl;
		cin >> tried_password;
			if(tried_password == password)
			{
				cout << "The password is correct" << endl;
			}
			
			else
			{
				cout << "put ur ass out of here" << endl;
				exit(0);
			}
		exit(0);
	}		

	else
	{
		cout << "seriusly? put ur ass out of here" << endl;
		exit(0);
	}

		
	return 0;
}
