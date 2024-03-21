// Nurullah Ozturk 3/21/2024
// Chapter 6 Exercise 4

#include "std_lib_facilities.h"

/*
4. Define a class Name_value that holds a string and a value. Rework exercise
19 in Chapter 4 to use a vector<Name_value> instead of two vectors.

chapter 4 exercise 19:
19. Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22. For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding positions,
so that if names[7]=="Joe" then scores[7]==17). Terminate input
with NoName 0. Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.
*/

class Name_value {
public:
	Name_value(string n, int s) : name(n), score(s) {}
	string name;
	int score;
};

int main()
{
try {
	vector<Name_value> pairs;

	string n;
	int v;

	cout << "Please enter name-and-value pairs, e.g. Joe 17 Barbara 22\n"
		<< "(To terminate the program, enter: NoName 0)\n";

	while (cin >> n >> v && n != "NoName") {
		for (int i = 0; i < pairs.size(); ++i)
			if (n == pairs[i].name) error("duplicate: ", n);
		pairs.push_back(Name_value(n, v));
	}

	if (!cin) error("bad input");
	for (int i = 0; i < pairs.size(); ++i)
		cout << '(' << pairs[i].name << ", " << pairs[i].score << ")\n";

}
catch (exception& e) {
	cerr << e.what() << endl;
	//keep_window_open("~1");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~2");
	return 2;
}
}