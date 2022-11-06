#include <iostream>
#include <complex>
using namespace std;

// inline function call by reference
inline void swap (int& i, int& j){
	int temp = i;
	i = j;
	j = temp;
}

// inline function call by reference, function overloaded
inline void swap (double& i, double& j){
	double temp = i;
	i = j;
	j = temp;
}

// endl is equivalent to new line char in C

// Use of generics
// Template T is used
template<class T>
inline void swapt(T& d, T& s) {
	T tmp = d;
	d = s;
	s = tmp;
}

int main () {

	// Demonstrating inline functions
	// Demonstrating call by reference
	// Demonstrating function overloading
	int m = 5, n = 6;
	double x = 5.3, y = 10.3;
	complex<double> r(2.4, 3.5), s(5.5, 7.2);

	cout <<"input : " << m <<", " << n << endl;
	swap (m, n);
	cout <<"ouput : " << m <<", " << n << endl;
	
	cout <<"input : " << x <<", " << y << endl;
	swap (x, y);
	cout <<"ouput : " << x <<", " << y << endl;


	cout <<"input : " << m <<", " << n << endl;
	swapt (m, n);
	cout <<"ouput : " << m <<", " << n << endl;
	cout <<"input : " << x <<", " << y << endl;
	swapt (x, y);
	cout <<"ouput : " << x <<", " << y << endl;
	cout <<"input : " << r <<", " << s << endl;
	swapt (r, s);
	cout <<"ouput : " << r <<", " << s << endl;
	return 0;
}
