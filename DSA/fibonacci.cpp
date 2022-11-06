#include <iostream>
#include <vector>

using namespace std;

// A C++ program to calculate fibonacci number in an effective way
// Fn = Fn-1 + Fn-2 ie Sum of last 2 fibonacci numbers


// Function to calculate fibonacci number
int CalcFibonacci(int n ) {
	vector<long long int> f;
  
	// In case 0 or 1 just return
	if (n == 0 || n == 1) return n;
  
	// Store 1st and 2nd fibonacci number to a vector
	f.push_back(0);
	f.push_back(1);

  // Sum of previous 2 fibonacci number is equal to current
	for (int i = 2; i <= n; i++) {
		auto tmp = f[i-1] + f[i-2];
		f.push_back(tmp);
	}

	// Return last fibonacci number
	return f[n];
		
}

int main() {
	int n;
	long long int f;

	// Read n value
	cout <<"Enter N for fibonacci : ";
	cin >> n;

	f = CalcFibonacci(n);
	cout <<"F_" << n << " : " << f << endl;
	return 0;
}
