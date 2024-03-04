#include "std_lib_facilities.h"

// Unsafe conversions
int main()
{
	double d = 0;
	while (cin >> d) {
		int i = d; // try to squeeze a double into an int
		char c = i; // try to squeeze an int into a char
		int i2 = c; // get the integer value of the character
		cout << "d==" << d // the original double
			<< " d-->i\n" 
			<< "i==" << i // converted to int
			<< " i-->c\n"
			<< "c==" << c // the char
			<< " c-->i2\n"
			<< "i2==" << i2 << "\n"; // int value of char
	}
}