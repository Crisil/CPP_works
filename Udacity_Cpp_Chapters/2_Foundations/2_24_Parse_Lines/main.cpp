#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void ReadBoard (string path)
{
	fstream Fp (path, ios::in);
	string line;
	cout << "Read file from path: " << path << "\r\n";

	while(getline(Fp, line))
		cout << line << "\r\n";
}

vector<int> ParseLine(string line)
{
	istringstream sline(line);
	vector<int> row;
	int n;
	char c;

	while (sline >> n >> c)
		row.push_back(n);

	return row;
}

int main()
{
	ReadBoard("../files/1_board");
	vector<int> b;	
	vector<int>::iterator it;
	string a ("0, 1, 0, 0, 0, 0");
 
	cout << "Parse Lines ...\r\n";
	b = ParseLine(a);
	for (it = b.begin(); it != b.end(); it++)
		cout << *it << " ";

	cout << "\r\n";
	
	return 0;
}
