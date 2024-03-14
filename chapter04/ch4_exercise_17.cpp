#include "std_lib_facilities.h"
/*
17. Write a program that finds the min, max, and mode of a sequence of
strings.
*/

vector<string> words;
int max_mode = 0;
string mode;

int main()
{
try {
	cout << "Please enter a sequence of strings\n";
	string word;
	int mode_count;
	while (cin >> word) {
		words.push_back(word);
		mode_count = 0;
		for (int i = 0; i < words.size(); ++i) {
			if (words[i] == word) ++mode_count;
		}
		if (max_mode < mode_count) {
			max_mode = mode_count;
			mode = word;
		}
	}

	sort(words);

	cout << "min: " << words[0] << "\n"
		<< "max: " << words[words.size() - 1] << "\n"
		<< "mode: " << mode << "\n";
}
catch (runtime_error& e) {
	cout << e.what() << "\n";
	//keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	//keep_window_open("~");
}
}