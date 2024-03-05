#include "std_lib_facilities.h"
/*
9. Write a program that converts spelled-out numbers such as “zero” and
“two” into digits, such as 0 and 2. When the user inputs a number, the
program should print out the corresponding digit. Do it for the values 0,
1, 2, 3, and 4 and write out not a number I know if the user enters something
that doesn’t correspond, such as stupid computer!.
*/
int main()
{
	cout << "Please spell-out a digit, e.g. four: \n";
	string str;
	cin >> str;

	if (str == "zero") cout << "You entered digit 0\n";
	else if (str == "one") cout << "You entered digit 1\n";
	else if (str == "two") cout << "You entered digit 2\n";
	else if (str == "three") cout << "You entered digit 3\n";
	else if (str == "four") cout << "You entered digit 4\n";
	else cout << "Not a number I know\n";

}