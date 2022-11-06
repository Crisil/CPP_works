#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// A program to determine largest number formed from the group
// of numbers eg: [2, 21] --> 221

// Concatenate 2 number and determine the greatest value
int compare (string X, string Y) {
	auto XY = X.append(Y);
	auto YX = Y.append(X);

	return XY.compare(YX) > 0 ? 1 : 0;
}

int main (){
	vector<string> arr;
	string str;
	int N;

	cout << "Enter Maximum numbers : ";
	cin >> N;

	for (int i = 0; i < N; ++i) {
		cout << i + 1 <<"th : ";
		cin >> str;
		arr.push_back(str);
	}
  
	// sort based of compare function
	sort(arr.begin(), arr.end(), compare);

	for (size_t i = 0; i != arr.size(); ++i)
		cout << arr[i];
	cout << endl;

	return 0;
}
