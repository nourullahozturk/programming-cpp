#include "std_lib_facilities.h"
/*
8. Write a program to test an integer value to determine if it is odd or
even. As always, make sure your output is clear and complete. In other
words, don’t just output yes or no. Your output should stand alone,
like The value 4 is an even number. Hint: See the remainder (modulo)
operator in §3.4.
*/
int main()
{
	cout << "Please enter an integer: \n";

	int val;
	cin >> val;

	if (val % 2 == 0) cout << "The value " << val << " is an even number.\n";
	else cout << "The value " << val << " is an odd number.\n";
}