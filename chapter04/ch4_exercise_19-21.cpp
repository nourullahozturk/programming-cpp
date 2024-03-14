#include "std_lib_facilities.h"
/*
19. Write a program where you first enter a set of name-and-value pairs, such
as Joe 17 and Barbara 22. For each pair, add the name to a vector called
names and the number to a vector called scores (in corresponding positions,
so that if names[7]=="Joe" then scores[7]==17). Terminate input
with NoName 0. Check that each name is unique and terminate with an
error message if a name is entered twice. Write out all the (name,score)
pairs, one per line.

20. Modify the program from exercise 19 so that when you enter a name, the
program will output the corresponding score or name not found.

21. Modify the program from exercise 19 so that when you enter an integer,
the program will output all the names with that score or score not found.
*/

vector<string> names;
vector<int> ages;

void find_name(string n)
{
	bool no_match = true;	// change to false when we have a match
	for (int i = 0; i < names.size(); ++i) {
		if (names[i] == n) {
			cout << "We found the name:\n" << names[i] << " " << ages[i] << "\n";
			no_match = false;
		}
	}
	if (no_match) cout << "name not found\n";
}

void find_scores(int s)
{
	bool no_match = true;	// change to false when we have a match
	for (int i = 0; i < ages.size(); ++i) {
		if (ages[i] == s) {
			cout << names[i] << " " << ages[i] << "\n";
			no_match = false;
		}
	}
	if (no_match) cout << "score not found\n";
}

int main()
{
try {
	cout << "Please enter name-and-value pairs, e.g. Joe 17 Barbara 22\n"
		<< "(To terminate the program, enter: NoName 0)\n";
	string name;
	int age;
	while (cin >> name >> age && name != "NoName") {
		//if (name == "NoName" && age == 0) break;
		for (string n : names) if (n == name) error("duplicate name!");
		names.push_back(name);
		ages.push_back(age);
	}
	if (!cin) error("bad input");
	for (int i = 0; i < names.size(); ++i)
		cout << names[i] << " " << ages[i] << "\n";

	cout << "Enter a name to see whether it's among the names you entered\n";
	cin >> name;
	find_name(name);

	cout << "Enter an age to see all names that has that age\n";
	cin >> age;
	find_scores(age);
	
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