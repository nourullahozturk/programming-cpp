#include "std_lib_facilities.h"
/*
11. Write a program that writes out the first so many values of the Fibonacci
series, that is, the series that starts with 1 1 2 3 5 8 13 21 34. The next
number of the series is the sum of the two previous ones. Find the largest
Fibonacci number that fits in an int.
*/

bool is_overflow(int lhs, int rhs)
// checks for overflow when adding two integers
{
	if (lhs >= 0) {
		if (INT_MAX - lhs < rhs) return true;
	}
	else {
		if (rhs < INT_MIN - lhs) return true;
	}
	return false;
}


int main()
{
try {
	cout << "Fibonacci series: \n";
	constexpr int half_max = 1073741824;	// half of the max integer limit
	int p = 1;
	int n = 1;
	int temp;
	cout << "1 1 ";
	while (true) {
		if (n > half_max && is_overflow(p, n)) {	// check half_max first for optimization
			// (overflow can occur only if n is larger than half_max)
			cout << "\nmax fibonacci number that an int can hold is " << n << "\n";
			break;
		}
		temp = n;	// save the current value
		n = p + n;	// current value is previous + current value
		p = temp;	// new previous value is the saved current value
		cout << n << ' ';
	}

}
catch (runtime_error& e) {
	cout << e.what() << "\n";
	//keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	//keep_window_open("~");
}
}