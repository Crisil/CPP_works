#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void ReadBoard(string fpath)
{
	fstream Fp (fpath, ios::in);
	string line;
	while (getline (Fp, line))
		cout << line << "\r\n";
}

int main()
{
  string fpath = "board";
	ReadBoard (fpath);
	
	return 0;
}

