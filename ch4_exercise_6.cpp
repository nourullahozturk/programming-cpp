#include "std_lib_facilities.h"
/*
6. Make a vector holding the ten string values "zero", "one", . . . "nine".
Use that in a program that converts a digit to its corresponding
spelled-out value; e.g., the input 7 gives the output seven. Have the same
program, using the same input loop, convert spelled-out numbers into
their digit form; e.g., the input seven gives the output 7.
*/

int main()
{
	vector<string> digits_sp = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	cout << "Input a digit (e.g. 7 or seven):\n";
	string input;
	while (cin >> input) {
		for (int i = 0; i < digits_sp.size(); ++i) {
			if (input == digits_sp[i]) {
				cout << i << "\n";
				break;
			}
		}
		for (int i = 0; i < digits.size(); ++i) {
			if (input == digits[i]) {
				cout << digits_sp[i] << "\n";
				break;
			}
		}
	}
}