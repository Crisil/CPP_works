#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
  
//template <typename T, typename V>
//T sumTwo (T a, V b)
//{
//  T sum;
//  sum = a + b;
//  return sum;
//}

int main()
{
  string line;
  std::cout <<"Hello World\r\n";

//  fstream FILE ("file.txt", ios::app);
//  if (FILE.is_open()) {
//    FILE << "Hello C++ 0\r\n";
//    FILE << "Hello C++ 1\r\n";
//    FILE << "Hello C++ 2\r\n";
//    FILE << "Hello C++ 3\r\n";
//    FILE << "Hello C++ 4\r\n";
//    FILE.close();
//  }
//  else {
//    cout << "Unable to open FILE\r\n";
//  }
//
//
//  fstream FILEr ("file.txt", ios::in);
//  if (FILEr.is_open()) {
//    while (getline (FILEr, line))
//      cout << line << "\r\n";
//  }
//  else 
//    cout <<"Unable to open file\r\n";

//  cout << "Enter your name\r\n";
//  getline(cin, line);
//  cout << "Name :" << line << "\r\n";
//  float length = 0;
//  float width = 0;
//  float area = 0;
//
//  cout << "Enter Length:";
//  getline(cin, line);
//  stringstream(line) >> length;
//
//  cout << "Enter Width:";
//  getline(cin, line);
//  stringstream(line) >> width;
//
//  area = length * width;
//  cout << "Area:" << area << "\r\n";
//  float a = 5.6;
//  int b = 5;
//  float ans = sumTwo(a, b);
//  cout << "Ans : " << ans << "\r\n";

  vector<int> vInts;
  vector<int>::iterator it;
  cout << "Size : " << vInts.size() << "\r\n";

  vInts.assign(6, 18);
  cout << "Size : " << vInts.size() << "\r\n";

  vInts.push_back(12);
  vInts.push_back(45);
  vInts.push_back(10);
  vInts.push_back(17);

  cout << "push_back - Size : " << vInts.size() << "\r\n";
  it = vInts.begin() + 2;
  vInts.insert(it, 9);
  cout << "insert - Size : " << vInts.size() << "\r\n";
  it = vInts.begin() + 2;
  vInts.emplace(it, 1);
  cout << "emplace - Size : " << vInts.size() << "\r\n";

  for (it = vInts.begin(); it != vInts.end(); it++)
    cout << "Value : " << *it << "\r\n";
  cout << endl;
	vInts.erase(vInts.begin(), vInts.begin()+4);
  for (it = vInts.begin(); it != vInts.end(); it++)
    cout << "Value : " << *it << "\r\n";


  return 0;
}
