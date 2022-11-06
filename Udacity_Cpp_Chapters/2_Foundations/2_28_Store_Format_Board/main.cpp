#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum class State
{
	kEmpty,
	kObstacle
};

string CellString(State cell)
{
	switch (cell)
	{
		case State::kObstacle:
			return "T ";
		default:
		  return "0 ";
	}
}


vector<State> ParseLine(string line)
{
	int n;
	char c;
	istringstream sline(line);
	vector<State> row;

	while (sline >> n >> c)
	{	
		row.push_back(n == 0 ? State::kEmpty : State::kObstacle);
	}
	return row;
}


vector<vector<State>> ReadBoard(string path)
{
	vector<vector<State>> board;
	fstream Fp (path, ios::in);
	string line;
	while(getline(Fp, line))
	{
		vector<State> row = ParseLine(line);
    board.push_back(row);
	}
	return board;
}

void PrintBoard(vector<vector<State>> board)
{
	for (auto i : board)
	{
		for (auto v : i)
			cout << CellString(v) << " ";
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
