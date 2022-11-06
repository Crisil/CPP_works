#include <iostream>
#include <vector>

using namespace std;

void PrintBoard (vector<vector<int>> board)
{
	for (auto v : board)
	{
		for (int i : v)
			cout << i << " ";
		cout << "\r\n";
	}
}


int main()
{
	vector<vector<int>> board = {{0, 1, 0, 0, 0, 0},
		                     {0, 1, 0, 0, 0, 0},
		                     {0, 1, 0, 0, 0, 0},
		                     {0, 1, 0, 0, 0, 0},
		                     {0, 0, 0, 0, 1, 0}};

	cout << "Hello World! \r\n";
	PrintBoard(board);

	return 0;
}

