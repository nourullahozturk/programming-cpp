#include "std_lib_facilities.h"
/*
7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.
*/
int main()
{
	cout << "Simple Calculator\n"
		<< "Please enter two single-digit numbers written as either digits\n"
		<< "or spelled out followed by an operation(+, -, / , *)\n"
		<< "e.g. 6 7 + or six seven + \n";
	
	vector<string> digits_sp = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string d1, d2;
	int n1, n2;
	char op;
	while (cin >> d1 >> d2 >> op) {
		// loop to convert string inputs to corresponding numbers
		for (int i = 0; i < digits_sp.size(); ++i) {
			if (d1 == digits_sp[i] || d1 == digits[i]) n1 = i;
			if (d2 == digits_sp[i] || d2 == digits[i]) n2 = i;
		}
		// switch statement to choose and apply an operation
		switch (op)
		{
		case '+':
			cout << "The sum of " << n1 << " and " << n2 << " is " << n1 + n2 << "\n";
			break;
		case '-':
			cout << "The difference of " << n1 << " and " << n2 << " is " << n1 - n2 << "\n";
			break;
		case '/':
			cout << "The divison of " << n1 << " and " << n2 << " is " << n1 / n2 << "\n";
			break;
		case '*':
			cout << "The multiplication of " << n1 << " and " << n2 << " is " << n1 * n2 << "\n";
			break;
		default:
			cout << "Unknown operation\n";
			break;
		}
	}
}