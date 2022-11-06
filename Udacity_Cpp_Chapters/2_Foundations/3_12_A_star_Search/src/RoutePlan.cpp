#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Class will all the states to be used in the Maze
enum class State
{
	kEmpty,
	kObstacle,
  kClosed,
	kPath,
	kStart,
	kFinish
};

/**
 * Movements allowed in XY directions
 * |-----------------
 * |      Y
 * |
 * | X
 * |
 */
const int delta[4][2] = {{-1,  0}, 
		                     { 0, -1},
												 { 1,  0},
												 { 0,  1}
	                      };

/**
 * Format each cells will a character for displaying maze
 * @param cell Emumeration Class
 * @return Maze character
 * O - Obstacle
 * Y - Path Taken
 * S - Starting Point
 * F - Finish Point 
 * E - Empty Path
 */
string CellString(State cell)
{
	switch (cell)
	{
		case State::kObstacle:
			return "O ";
		case State::kPath:
			return "Y ";
	  case State::kStart:
			return "S ";
		case State::kFinish:
			return "F ";
		default:
		  return "E ";
	}
}

/**
 * A function to parse input line. 
 * Read a line string and convert it to a row will elements marked
 * @param line input string of maze
 * @return vector of input maze
 */
vector<State> ParseLine(string line)
{
	int n;
	char c;
	istringstream sline(line);
	vector<State> row;

	while (sline >> n >> c && c == ',')
	{	
		row.push_back(n == 0 ? State::kEmpty : State::kObstacle);
	}
	return row;
}

/**
 * A function to Read Maze from the path specified
 * Possible values are 0 and 1. A 1 is considered as a n obstacle
 * @param path file path
 * @return 2D vector of Maze marked as either Empty Or Obstacle
 */
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

/**
 * A function to print Maze with its markings
 * @param baord Maze
 * @return None
 */
void PrintBoard(vector<vector<State>> board)
{
	for (auto i : board)
	{
		for (auto v : i)
			cout << CellString(v) << " ";
		cout << "\r\n";
	}
}

/**
 * A function to compare two node based on their f values
 * @param node1 First Vector
 * @param node2 Second Vector
 * @return True if node1 f value > node2 f value
 */
bool Compare (vector<int> node1, vector<int> node2)
{
	int f1 = node1[2] + node1[3];
	int f2 = node2[2] + node2[3];
	return f1 > f2;
}

/**
 * A function find the H() value
 * @param (x, y) Input co-ordinates
 * @return H value
 */
int Heuristic (int x1, int y1, int x2, int y2)
{
	return (abs(x2 - x1) + abs(y2 - y1));
}

/// Helper function to Sort given Vector
void CellSort(vector<vector<int>> *v)
{
	sort(v->begin(), v->end(), Compare);
}

/**
 * A function to check whether cells are inside the Maze and its empty
 * @param x, y Cell Co-ordinates
 * @param grid Maze
 * @return True if Cell inside maze and its empty
 */
bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{
	bool on_grid_x = (x >= 0 && x < grid.size());
	bool on_grid_y = (y >= 0 && y < grid[0].size());
  if (on_grid_x && on_grid_y)
	  return grid[x][y] == State::kEmpty;
	return false;
}

/**
 * A function to add cell to open list and function mark the Cell as closed
 * @param x y Cell Co-ordinates
 * @param g, h G and H value of Cells 
 */
void AddToOpen(int x, int y, int h, int g, vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
	vector<int> node {x, y, g, h};
	openlist.push_back(node);
	grid[x][y] = State::kClosed;
}

/**
 * A function to identify neighbour cells
 * @param current Current cell
 * @param goal Goal (Destination) Cell Co-ordinates
 * @param openlist List of Open Cells
 * @param grid Maze
 * @return None
 */
void ExpandNeighbours(vector<int> &current, int goal [], vector<vector<int>> &openlist, vector<vector<State>> &grid)
{
	// Fetch current values of cell
	int x = current[0];
	int y = current[1];
	int g = current[2];

	// Calculate H vale from current Cell to Goal Cells
	int h = Heuristic(x, y, goal[0], goal[1]);

	// Iterate through all available motion positions
	// 4 motions are available UP, DOWN, LEFT, RIGHT
	for (int i = 0; i < 4; i++)
	{
		// Get new Cells
		int x2 = x + delta[i][0];
		int y2 = y + delta[i][1];

		// Are these new cells valid in thr Maze
		if (CheckValidCell(x2, y2, grid))
		{
			// Increment G and Caluclate H vale from new cell to goal and add new cell to open list
			int g2 = g + 1;
			int h2 = Heuristic(x2, y2, goal[0], goal[1]);
			AddToOpen(x2, y2, g2, h2, openlist, grid);
		}
	}
}

/**
 * A function to Search A* algorithm
 * @param grid Maze
 * @param init Starting location
 * @param goal Final location
 * @return Solution if found else Null
 */
vector<vector<State>> Search (vector<vector<State>> grid, int init[], int goal[])
{
	vector<vector<int>> open;
	int x = init[0];
	int y = init[1];
	int g = 0;

	// Find H and add starting cell to open list
	int h = Heuristic(x, y, goal[0], goal[1]);
	AddToOpen(x, y, g, h, open, grid);

	while(open.size() > 0)
	{
		// Sort Open list and pick the cell with least F value, CellSort helper implements this
		CellSort(&open);		
		auto current = open.back();			// Cell with least f value
		open.pop_back();

		// Assign this cell to solution path
		x = current[0];
		y = current[1];
		grid[x][y] = State::kPath;

		// Cell matches Goal then return grid
		if (x == goal[0] && y == goal[1])
		{
			grid[init[0]][init[1]] = State::kStart;
			grid[goal[0]][goal[1]] = State::kFinish;
			return grid;
		}
    
		// Find neighbour cells
		ExpandNeighbours(current, goal, open, grid);
	}
	return vector<vector<State>>{};
}

int main()
{
	// input maze file
	string file = "../files/1_board";
	int init[2] = {0, 0};  // Starting Position
	int goal[2] = {0, 4};  // Destination Position

	cout << "Maze ...\r\n";
	auto board = ReadBoard(file);
	PrintBoard(board);
  cout << "\r\n";	

	cout << "Maze Solution...\r\n";
	auto solution = Search(board, init, goal);	
	if (solution.empty())
		cout << "No Path Found ....\r\n";
	else
	  PrintBoard(solution);
	return 0;
}
