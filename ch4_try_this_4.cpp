#include "std_lib_facilities.h"

// implement a square function
int square(int x) {
	int sum = 0;
	for (int i = 0; i < x; ++i)
		sum += x;
	return sum;
}

int main()
{
	int input;
	cin >> input;
	cout << "Square of " << input << " is " << square(input) << "\n";
}