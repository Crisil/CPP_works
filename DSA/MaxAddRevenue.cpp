// Calc the maximum revenue possible from ads
// There are 2 sequence ai and bi
// ai - profit per click for ith slot
// bi - average number of clicks per daty for i th slot
// Sort 2 sequence and find there products -- Maximum revenue

#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

bool compare (int a, int b){
	return a > b;
}

// Calc Max Revenue
int CalcMaxRev(vector<int> profits, vector<int> clicks) {
	int sum = 0;
	// sort sequence
	sort(profits.begin(), profits.end(), compare);
	sort(clicks.begin(), clicks.end(), compare);

	// Find product of sums
	for (int i = 0; i != profits.size(); ++i)
		sum += profits[i] * clicks[i];

	return sum;
}

int main(){
	int num_slots;
	int tmp;
	vector<int> profits;
	vector<int> clicks;
	int MaxProfit;

	cout << "Number of slots : ";
	cin >> num_slots;
	cout << "Profits for ith slots : ";
	for (int i = 0; i != num_slots; ++i) {
		cin >> tmp;
		profits.push_back(tmp);
	}

	cout << "Clicks for ith slots : ";
	for (int i = 0; i != num_slots; ++i) {
		cin >> tmp;
		clicks.push_back(tmp);
	}

	MaxProfit = CalcMaxRev(profits, clicks);
	cout << "MaxProfit : " << MaxProfit << endl;

	return 0;
}
