#include "std_lib_facilities.h"
/*
4. Write a program that prompts the user to enter two integer values. Store
these values in int variables named val1 and val2. Write your program to
determine the smaller, larger, sum, difference, product, and ratio of these
values and report them to the user.

5. Modify the program above to ask the user to enter floating-point values
and store them in double variables. Compare the outputs of the two programs
for some inputs of your choice. Are the results the same? Should
they be? What’s the difference?
*/
int main()
{
	cout << "Please enter two integers: \n";

	int val1, val2;
	cin >> val1 >> val2;

	int larger, smaller;
	if (val1 < val2) {
		smaller = val1;
		larger = val2;
	}
	else {
		smaller = val2;
		larger = val1;
	}
	
	cout << "smaller: " << smaller << "\tlarger: " << larger
		<< "\tsum: " << val1 + val2 << "\tdifference: " << val1 - val2
		<< "\tproduct: " << val1 * val2 << "\tratio: " << val1 / val2
		<< "\n";
}