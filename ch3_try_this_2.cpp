#include "std_lib_facilities.h"

// simple program to exercise operators
int main()
{
	cout << "Please enter an integer value\n";
	int n;
	cin >> n;
	double d = n; // assigned to a double to take sqrt later
				  // sqrt() is not defined for an int
	cout << "n == " << n
		<< "\nn + 1 == " << n + 1
		<< "\nthree times n == " << n * 3
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsquare root of n == " << sqrt(d)
		<< "\n" << (n / 5 * 5 + n % 5 == n);
}