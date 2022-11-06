#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string a("199 2 1");
	istringstream myStream(a);
	int n;
	myStream >> n;
	cout << n << "\r\n";

	myStream >> n;
	cout << n << "\r\n";
	
	myStream >> n;
	cout << n << "\r\n";

	return 0;
}

