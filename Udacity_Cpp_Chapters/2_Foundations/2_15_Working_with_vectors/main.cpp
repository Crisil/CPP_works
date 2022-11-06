#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> a = {0, 1, 2, 3};
	cout << "a = \r\n";
	for (size_t i = 0; i != a.size(); i++)
	  cout << a[i] << " ";

	cout << "\r\n";

	vector<vector<int>> b = {{0, 1, 2, 3},
					                 {4, 5, 6, 7},
													 {8, 9, 10, 11}};

	cout << "b.size() = " << b.size() << "\r\n";

	cout << "b = \r\n";
	for (size_t i = 0; i != b.size(); i++)
	{		
		for (size_t j = 0; j != b[i].size(); j++)
			cout << b[i][j] << " ";
		cout << "\r\n";
	}

	cout << "\r\n";

	// Range Based Loop
	cout << "Range Based Loop ...\r\n";
	cout << "b = \r\n";
	for (auto v : b)
	{
		for (int i : v)
			cout << i << " ";
		cout << "\r\n";
	}


	return 0;
}

