#include "std_lib_facilities.h"
/*
14. Read (day-of-the-week,value) pairs from standard input. For example:
Tuesday 23 Friday 56 Tuesday –3 Thursday 99
Collect all the values for each day of the week in a vector<int>. Write out
the values of the seven day-of-the-week vectors. Print out the sum of the
values in each vector. Ignore illegal days of the week, such as Funday,
but accept common synonyms such as Mon and monday. Write out the
number of rejected values.
*/

vector<int> mon;
vector<int> tue;
vector<int> wed;
vector<int> thu;
vector<int> fri;
vector<int> sat;
vector<int> sun;

int vsum(vector<int> v) {
	int sum = 0;
	for (int x : v) sum += x;
	return sum;
}

int main()
{
try {
	cout << "Please enter a sequence of day-of-the-week followed by a value(e.g. Friday 56):\n"
		<< "To finish, write out 'End 0'\n";
	string d;
	int v, rejected = 0;
	while (cin >> d >> v) {
		if (d == "Monday" || d == "mon" || d == "monday" || d == "Mon")
			mon.push_back(v);
		else if (d == "Tuesday" || d == "tue" || d == "tuesday" || d == "Tue")
			tue.push_back(v);
		else if (d == "Wednesday" || d == "wed" || d == "wednesday" || d == "Wed")
			wed.push_back(v);
		else if (d == "Thursday" || d == "thu" || d == "thursday" || d == "Thu")
			thu.push_back(v);
		else if (d == "Friday" || d == "fri" || d == "friday" || d == "Fri")
			fri.push_back(v);
		else if (d == "Saturday" || d == "sat" || d == "saturday" || d == "Sat")
			sat.push_back(v);
		else if (d == "Sunday" || d == "sun" || d == "sunday" || d == "Sun")
			sun.push_back(v);
		else if (d == "End")
			break;
		else ++rejected;
	}
	if (!cin) error("bad input");
	cout << "Sum of the values of the day\n"
		<< "Monday: " << vsum(mon) << '\n'
		<< "Tuesday: " << vsum(tue) << '\n'
		<< "Wednesday: " << vsum(wed) << '\n'
		<< "Thursday: " << vsum(thu) << '\n'
		<< "Friday: " << vsum(fri) << '\n'
		<< "Saturday: " << vsum(sat) << '\n'
		<< "Sunday: " << vsum(sun) << '\n'
		<< "amount of rejected values: " << rejected << '\n';
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