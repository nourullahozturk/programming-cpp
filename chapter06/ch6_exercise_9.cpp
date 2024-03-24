// Nurullah Ozturk 3/24/2024
// Chapter 6 Exercise 9

#include "std_lib_facilities.h"

/*
9. Write a program that reads digits and composes them into integers. For
example, 123 is read as the characters 1, 2, and 3. The program should
output 123 is 1 hundred and 2 tens and 3 ones. The number should be
output as an int value. Handle numbers with one, two, three, or four
digits. Hint: To get the integer value 5 from the character '5' subtract '0',
that is, '5'–'0'==5.
*/

int main()
{
try {
	vector<int> digit;		// collect digits here
	vector<string> unit;	// unit names go here
	unit.push_back(" ones ");
	unit.push_back(" tens ");
	unit.push_back(" hundreds ");;
	unit.push_back(" thousands ");
	unit.push_back(" tens of thousands ");
	unit.push_back(" hundreds of thousands ");
	unit.push_back(" millions ");
	unit.push_back(" tens of millions ");
	unit.push_back(" hundreds of millions ");

	/*
		note that the size of the unit vector is used to determine how many digits
		we can handle. Not magic constant has been introduced.
	*/

	cout << "Please enter an integer with no more than " << unit.size()
		<< "\ndigits followed by semicolon and a newline: ";
	char ch;
	while (cin >> ch) {
		if (ch < '0' || ch > '9') break;	// any non-digit acts as a terminator
		digit.push_back(ch - '0');
	}

	if (digit.size() == 0) error("no digits");
	if (unit.size() < digit.size()) error("Sorry, cannot handle that many digits");

	// write out the number
	for (int i = 0; i < digit.size(); ++i)
		cout << char('0' + digit[i]);
	cout << '\n';

	// write the digits with their units
	// also compute the integer value:
	int num = 0;
	for (int i = 0; i < digit.size(); ++i){
		if (digit[i])	// don't mention a unit if its count is zero
			cout << digit[i] << unit[digit.size() - i - 1];
		num = num * 10 + digit[i];
	}
	cout << "\nthat is " << num << '\n';
}
catch (exception& e) {
	cerr << e.what() << endl;
	//keep_window_open("~1");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	//keep_window_open("~2");
	return 2;
}
}