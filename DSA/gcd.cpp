#include <iostream>
using namespace std;

// A function to calculate GCD of 2 number effiecently
// GCD(a, b) = GCD (b, a%b)
int gcd (long long a, long long b) {
	if (!b) return a;

	auto tmp = a%b;
	gcd(b, tmp);
}

int main () {
	long long a, b, g;
	cout <<"Enter numbers a, b with a > b : ";
	cin >> a >> b;
  
	g = gcd(a, b);
	cout <<"GCD of " << a << " & " << b << " : " << g << endl;

	return 0;
}
