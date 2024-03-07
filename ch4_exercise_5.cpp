#include "std_lib_facilities.h"
/*
5. Write a program that performs as a very simple calculator. Your calculator
should be able to handle the four basic math operations — add, subtract,
multiply, and divide — on two input values. Your program should prompt
the user to enter three arguments: two double values and a character to
represent an operation. If the entry arguments are 35.6, 24.1, and '+', the
program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6
we look at a much more sophisticated simple calculator.
*/

int main()
{
	cout << "Simple Calculator\n"
		<< "Please enter two number and a +,-,/ or * operation (e.g. 35.6 24.1 +)\n";
	double n1, n2;
	char op;
	cin >> n1 >> n2 >> op;

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