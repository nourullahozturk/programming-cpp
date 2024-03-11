#include "std_lib_facilities.h"
/*
16. In the drill, you wrote a program that, given a series of numbers, found
the max and min of that series. The number that appears the most times
in a sequence is called the mode. Create a program that finds the mode of
a set of positive integers.
*/

vector<int> inputs;
vector<int> set;
vector<int> counts;

// is number n in the set?
bool is_duplicate(vector<int> set, int n) {
	for (int i = 0; i < set.size(); ++i)
		if (set[i] == n) return true;
	return false;
}

int get_index(vector<int> set, int n) {
	for (int i = 0; i < set.size(); ++i) {
		if (set[i] == n) return i;
	}
	error("something went wrong!");
	return -1;
}

int main()
{
try {
	cout << "Please enter a set of positive integers: \n";
	int n;
	while (cin >> n) {
		if (n < 0) error("error: negative input");
		inputs.push_back(n);
	}
	for (int i = 0; i < inputs.size(); ++i) {
		if (!is_duplicate(set, inputs[i])) {
			set.push_back(inputs[i]);
			counts.push_back(1);
		}
		else {
			++counts[get_index(set, inputs[i])];
		}
	}

	// find the mode
	int mode = 0;
	int max = 0;
	for (int i = 0; i < set.size(); ++i) {
		if (counts[i] > max) {
			max = counts[i];
			mode = set[i];
		}
	}
	cout << "Mode is: " << mode << "\n";
	//cout << "count:\tnumber:\n";
	//for (int i = 0; i < set.size(); ++i) {
	//	cout << counts[i] << "\t" << set[i] << "\n";
	//}
}
catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}
}