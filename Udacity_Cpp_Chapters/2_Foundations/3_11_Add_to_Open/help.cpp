#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x = 5;
	int y = 4;
	int z = 9;
	int k = 3;
	vector<int> node{x, y, z, k};
  for (auto it : node)
		cout << it << " ";
	return 0;
}
