#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	string key = "word";
	string def_1 = "a unit of language";
	string def_2 = "speech or talk or word";
	string def_3 = "a short talk or coversation";
	string def_4 = "an expression or utterance";

	unordered_map<string, vector<string>> my_dict;
	if (my_dict.find(key) == my_dict.end())
	{
	  cout <<"The string word in not found in the dict\r\n";
		cout <<"Inser the pair ... \r\n";

		my_dict[key] = vector<string> {def_1, def_2, def_3, def_4};
	}

	cout <<"Key : " << key << "\r\n";
	auto def = my_dict[key];
	for (auto d : def)
		cout << d << "\r\n";

	return 0;
}

