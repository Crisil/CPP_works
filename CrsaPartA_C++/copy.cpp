#include <iostream>

using namespace std;

// Demonstrate class with multiple templates variable
// As it an array no need for &
// Function copies from src -> dst
template<class T1, class T2>
void copy(const T1 src[], T2 dst[], int size = 0) {
	for (int i = 0; i < size; ++i)
		dst[i] = static_cast<T2>(src[i]);
}

int main (){
	const int size = 3;
	double src[] = {5.2, 6.7, 8.1};
	int    dst[] = {0, 0, 0};

	cout <<"inputs : ";
	for (int i = 0; i < size; ++i)
		cout <<src[i] << ",";
	cout <<endl;

	copy(src, dst, 3);
	
	cout <<"outputs : ";
	for (int i = 0; i < size; ++i)
		cout <<dst[i] << ",";
	cout <<endl;

	return 0;
}
