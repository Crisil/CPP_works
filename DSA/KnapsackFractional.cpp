#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A greedy algorithm to solve fractional knapsack problem
// There are N items and a bag which can carry W weight
// Each items value (v) and weight (w) are provided
// Solution:
// Calculate value/weight ratio and sort it
// Pick item with highest ration & if item fully can't 
// be contains take fractional part!

// structure to hold value, weight & ratio
struct Items {
	int it;
	int vi;
	int wi;
	float ri;
};

// display vector
template<typename T>
void display (vector<T> vec){
	cout << "Vector : " << endl;
	for (auto i : vec) {
		cout << "Item : " << i.it << i.vi << ", " << i.wi << ", " << i.ri;
	  cout << endl;
	}
}

// comparison function
bool compare (Items i1, Items i2) {
	return i1.ri > i2.ri;
}

// Calc
float CalcMaxValforKnapSack(int W, vector<Items>& item_s, vector<vector<float>>& pitems) {
	float value = 0.0; // value present in knapsack
	float fractwht;

  // sort input vector based on the ratio of v/w
	sort(item_s.begin(), item_s.end(), compare);

	// iterate over the vectors
	// item weight less that knapsack total weight add value &
	// decrement knapsack weight
	// add fractional weight when needed and determine its value
	for (size_t i = 0; i != item_s.size(); ++i){
		if (item_s[i].wi < W){
			value += item_s[i].vi;
			W     -= item_s[i].wi;
			pitems.push_back({item_s[i].it, item_s[i].wi});
		} else {
			fractwht  = ((double) W / (double) item_s[i].wi);
			value    += (item_s[i].vi) * fractwht;
			pitems.push_back({item_s[i].it, fractwht*item_s[i].wi});
			break;
		}
	}
	return value;
}

int main (){
	int W, N;
	int v, w;
	float MaxVal;
	float r;
	vector<Items>item_s;
	vector<vector<float>> pitem;

	cout << "Enter Weight, Items : ";
	cin >> W >> N;

	for (int i = 0; i < N; i++) {
		cout << i+1 << "th Value, Weight :";
		cin >> v >> w;
		r = (double) v / (double) w;
		item_s.push_back({i, v, w, r});
	}
  
	MaxVal = CalcMaxValforKnapSack(W, item_s, pitem);
	cout << "MaxValue : " << MaxVal << endl;
	for (auto i : pitem) {
		cout << "Picked item : " << i[0] << " weight : " << i[1] << endl;
	}
	return 0;
}
