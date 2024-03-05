#include "std_lib_facilities.h"
/*
2. Write a program in C++ that converts from miles to kilometers.
Your program should have a reasonable prompt for the user to enter a
number of miles. Hint: There are 1.609 kilometers to the mile.
*/

int main()
{
	constexpr double mi_to_km = 1.609;
	cout << "Miles to Kilometer Converter\n"
		<< "Please enter a distance (in miles)\n";
	double input = 0;
	while (cin >> input) {
		cout << input << " miles is " << input * mi_to_km << " kilometer\n";
	}
}
