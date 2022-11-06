#include <iostream>
#include <vector>
using namespace std;

// A program to determine number of minimum ways a Money can be 
// changed given a set of coins

int MinMoneyChange(int S, vector<int> coins, int ncoins){
	int minways = 0;
	// Create a row with width S+1 ie 
	// if S = 5, col = 0, 1, 2, 3, 4, 5
	vector<int> row(S+1, 0);

	// Create a 2D arr with each row with a coin
	vector<vector<int>> arr(ncoins, row);

	// Find how many minimum coins[0] required to create the sum
	for (size_t j = 1; j < arr[0].size(); ++j) {
	  auto rem = j%coins[0];
	  if (!rem) 
	  	arr[0][j] = j/coins[0];
	}
  
	// Determine remaining possibilities using Dynamic Programming
	// Iterate over the coins and sum values
	for (size_t i = 1; i < ncoins; ++i) {
		for (size_t j = 0; j <= arr[i].size(); ++j) {
			// number of min ways to create the value using previous coins
			auto tmp = arr[i-1][j];
			// present coin in hand
			auto pcoin = coins[i];

			// sum is less than present coin, them we can create it using only
			// previous coins, hence copy from previous row
			// Otherwise find the min of previous coin & presents + extra
			if (j < coins[i])
				arr[i][j] = tmp;
			else
				arr[i][j] = min(tmp, 1 + arr[i][j - pcoin]);
		}
	}
  
	// Print Dynamic Table
  // for (auto v : arr) {
	// 	for (auto i : v) {
	// 		cout << i << " ";
	// 	}
	// 	cout << endl;
	// }
  minways = arr[ncoins-1][S];
	return minways;
}

int main () {
	int S = 0, n = 0, c;
	int minways = 0;
	vector<int> coins;

	cout << "Enter Sum , Num Coins : ";
	cin >> S >> n;

	for (int i = 0; i < n; i++) {
		cout << i + 1 <<"th : ";
		cin >> c;
		coins.push_back(c);
	}

	minways = MinMoneyChange(S, coins, n);
	cout << "Minimum number of coins to create S=" << S << " is : " << minways << endl;
	return 0;
}
