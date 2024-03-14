#include "std_lib_facilities.h"
/*
10. Write a program that takes an operation followed by two operands and
outputs the result. For example:
	+ 100 3.14
	* 4 5
Read the operation into a string called operation and use an
if-statement to figure out which operation the user wants, for example,
if (operation=="+"). Read the operands into variables of type double.
Implement this for operations called +, –, *, /, plus, minus, mul, and div
with their obvious meanings.
*/
int main()
{
	string operation;
	double number1, number2, result = 0;
	cout << "Enter an operation followed by two numbers (e.g. + 100 3.14): \n";
	cin >> operation >> number1 >> number2;

	if (operation == "+" || operation == "plus") result = number1 + number2;
	else if (operation == "-" || operation == "minus") result = number1 - number2;
	else if (operation == "*" || operation == "mul") result = number1 * number2;
	else if (operation == "/" || operation == "div") result = number1 / number2;
	else error("Unknown operation.\n");
	cout << "result: " << result << "\n";
}