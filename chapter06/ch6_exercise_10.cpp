// Nurullah Ozturk 3/26/2024
// Chapter 6 Exercise 10

#include "std_lib_facilities.h"

/*
	10. A permutation is an ordered subset of a set. For example, say you wanted
	to pick a combination to a vault. There are 60 possible numbers, and
	you need three different numbers for the combination. There are P(60,3)
	permutations for the combination, where P is defined by the formula

		P(a,b) = a!/(a-b)!

	where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.
	Combinations are similar to permutations, except that the order of the
	objects doesn’t matter. For example, if you were making a “banana split”
	sundae and wished to use three different flavors of ice cream out of five
	that you had, you wouldn’t care if you used a scoop of vanilla at the
	beginning or the end; you would still have used vanilla. The formula for
	combinations is

		C(a,b) = P(a,b) / b!

	Design a program that asks users for two numbers, asks them whether
	they want to calculate permutations or combinations, and prints out the
	result. This will have several parts. Do an analysis of the above requirements.
	Write exactly what the program will have to do. Then, go into
	the design phase. Write pseudo code for the program, and break it into
	sub-components. This program should have error checking. Make sure
	that all erroneous inputs will generate good error messages.
*/

// ask user for two positive integers
// ask user whether calculate permutation or combination
// do the calculation (write a function for each calculation)
// print results
// check errors
// do testing

int factorial(int n)
{
	if (n > 12) error("coudn't calculate factorial for values above 12");
	if (n < 2) return 1;
	int sum = 1;
	for (int i = 2; i <= n; ++i)
		sum *= i;
	return sum;
}

int permutation(int a, int b)
{
	return factorial(a) / factorial(a - b);
}

int combination(int a, int b)
{
	return permutation(a, b) / factorial(b);
}

int main()
{
try {
	cout << "Enter two integer followed by a calculation\n"
		<< "(p for permutaion and c for combination, e.g. 5 2 p)\n"
		<< "write 'q' to quit program\n";
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (!cin) error("only integer values are accepted");

		char c;
		cin >> c;
		if (!cin) error("you have to write a character (p or c)");

		if (c == 'p')
			cout << "P(" << a << "," << b << "): " << permutation(a, b) << "\n";
		else if (c == 'c')
			cout << "C(" << a << "," << b << "): " << combination(a, b) << "\n";
		else if (c == 'q')
			break;
		else
			cout << "unknown operation. calculation must be either p or c\n";
		cout << "Try again: ";
	}
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