#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<int> ParseLine(string line)
{
	int n;
	char c;
	istringstream sline(line);
	vector<int> row;

	while (sline >> n >> c)
		row.push_back(n);

	return row;
}


vector<vector<int>> ReadBoard(string path)
{
	vector<vector<int>> board;
	fstream Fp (path, ios::in);
	string line;
	while(getline(Fp, line))
	{
		vector<int> row = ParseLine(line);
    board.push_back(row);
	}
	return board;
}

void PrintBoard(vector<vector<int>> board)
{
	for (auto i : board)
	{
		for (auto v : i)
			cout << v << " ";
		cout << "\r\n";
	}
}

int main()
{
	string file = "../files/1_board";
	auto board = ReadBoard(file);
	PrintBoard(board);
	return 0;
}
