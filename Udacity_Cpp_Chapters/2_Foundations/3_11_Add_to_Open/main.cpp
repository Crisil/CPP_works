#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

enum class State
{
	kEmpty,
	kObstacle,
  kClosed
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

void AddToOpen(int x, int y, int h, int g, vector<vector<int>> &openNode, vector<vector<State>> &grid)
{
	vector<int> node {x, y, g, h};
	openNode.push_back(node);
	grid[x][y] = State::kClosed;
}

int main()
{
	string file = "../files/1_board";
	auto board = ReadBoard(file);
	PrintBoard(board);
	return 0;
}
