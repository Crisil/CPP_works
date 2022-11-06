#include <iostream>
using namespace std;

int main()
{
	int i = 2;
	int j = 3;
	int k = i + j;
	int &&l = i + j;

	cout << "k = " << k << " l = " << l << "\r\n";
	return 0;
}
