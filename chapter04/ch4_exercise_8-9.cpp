#include "std_lib_facilities.h"
/*
8. There is an old story that the emperor wanted to thank the inventor of
the game of chess and asked the inventor to name his reward. The inventor
asked for one grain of rice for the first square, 2 for the second, 4 for
the third, and so on, doubling for each of the 64 squares. That may sound
modest, but there wasn’t that much rice in the empire! Write a program to
calculate how many squares are required to give the inventor at least 1000
grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains.
You’ll need a loop, of course, and probably an int to keep track of which
square you are at, an int to keep the number of grains on the current
square, and an int to keep track of the grains on all previous squares. We
suggest that you write out the value of all your variables for each iteration
of the loop so that you can see what’s going on.

9. Try to calculate the number of rice grains that the inventor asked for in
exercise 8 above. You’ll find that the number is so large that it won’t fit
in an int or a double. Observe what happens when the number gets too
large to represent exactly as an int and as a double. What is the largest
number of squares for which you can calculate the exact number of
grains (using an int)? What is the largest number of squares for which
you can calculate the approximate number of grains (using a double)?

Answers

largest number of squares for which we can calculate the exact number of
grains (using an int) is 31. number of grains calculated for 31th square
is 1,073,741,824. Square of this number is 1.152921504606847e+18 which is
beyond the max size of an int. Max size of an int is btw -2,147,483,648
and +2,147,483,648.

largest number of squares for which we can calculate the exact number of
grains (using a double) is 1024. number of grains calculated for 1024th square
is 8.98847e+307. Square of this number is 8.07925929409e+615 which is beyond
the max size of a double. Max size of a double is btw 2.22507e-308 and
1.79769e+308.
*/

//int power(int base, int pow) {
//	int sum = 1;
//	for (int i = 0; i < pow; ++i) {
//		sum *= base;
//	}
//	return sum;
//}

double power(double base, int pow) {
	double sum = 1;
	for (int i = 0; i < pow; ++i) {
		sum *= base;
	}
	return sum;
}

int main()
{
	cout << "How many grains of rice do you want?\n";
	double input;
	double current_grains = 0, prev_grains = 0;
	cin >> input;

	int current_square = 0;
	for (int i = 0; i < 10000000; ++i) {
		++current_square;
		// to keep track of the grains on all previous squares
		prev_grains += current_grains;
		current_grains = power(2, i);
		
		cout << "current square: " << current_square << "  current grains: "
			<< current_grains;
		if (i != 0)
			cout << "  grains on all previous squares: " << prev_grains << "\n";
		else cout << "\n";

		if (current_grains + prev_grains > input) {
			cout << current_square << " squares are required to give at least "
				<< input << " grains.\n";
			break;
		}
	}
}