#include <chrono>
#include <iostream>

using namespace std;

int main()
{
	const int SIZE = 4;
	static int X[SIZE][SIZE];

	auto t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++)
		{
			X[i][j] = i + j;
			cout << &X[i][j] << " :i = " << i << " :j = " << j << "\r\n";
		}
	}
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
	cout << "Execution Time = " << duration << "\r\n";

	auto t3 = chrono::high_resolution_clock::now();
	for (int i = 0; i < SIZE; i++) 
	{
		for (int j = 0; j < SIZE; j++)
		{
			X[j][i] = i + j;
			cout << &X[j][i] << " :i = " << i << " :j = " << j << "\r\n";
		}
	}
	auto t4 = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(t4 - t3).count();
	cout << "Execution Time = " << duration << "\r\n";
	return 0;
}
