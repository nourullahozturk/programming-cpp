#include "std_lib_facilities.h"
/*
8. Write a program that reads and stores a series of integers and then computes
the sum of the first N integers. First ask for N, then read the values
into a vector, then calculate the sum of the first N values. For example:
“Please enter the number of values you want to sum:”
3
“Please enter some integers (press '|' to stop):”
12 23 13 24 15 |
“The sum of the fi rst 3 numbers ( 12 23 13 ) is 48.”
Handle all inputs. For example, make sure to give an error message if the
user asks for a sum of more numbers than there are in the vector.

9. Modify the program from exercise 8 to write out an error if the result
cannot be represented as an int.

10. Modify the program from exercise 8 to use double instead of int. Also,
make a vector of doubles containing the N–1 differences between adjacent
values and write out that vector of differences.
*/

bool is_overflow(double lhs, double rhs)
// checks for overflow when adding two integers
{
	if (lhs >= 0) {
		if (DBL_MAX - lhs < rhs) return true;
	}
	else {
		if (rhs < DBL_MIN - lhs) return true;
	}
	return false;
}

int main()
{
try {
	cout << "Please enter the number of values you want to sum:\n";
	int n;
	cin >> n;	// If extraction fails zero is written to n.
	// So, we handle a failed read by checking against zero
	if (n <= 0) error("the number of elements must be a positive integer");

	cout << "Please enter some floating-point numbers (press '|' to stop):\n";
	vector<double> v;
	vector<double> d;
	double x;
	for (int i = 0; cin >> x; ++i) {
		v.push_back(x);
		if (i != 0) d.push_back(v[i] - v[i - 1]);
	}

	if (v.size() < n) error("too few numbers; we need ", n);
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		if (is_overflow(sum, v[i])) error("the result is cannot be represented as a double");
		sum += v[i];
	}

	cout << "The sum of the first " << n << " numbers ( ";
	for (int i = 0; i < n; ++i) cout << v[i] << ' ';
	cout << ") is " << sum << '\n';

	cout << "The differences of adjacent numbers:\n";
	for (int i = 0; i < n - 1; ++i) cout << d[i] << ' ';
	cout << "\n";
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