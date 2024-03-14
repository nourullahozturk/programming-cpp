#include "std_lib_facilities.h"
/*
18. Write a program to solve quadratic equations. A quadratic equation is of
the form
	ax2 + bx + c = 0
If you don’t know the quadratic formula for solving such an expression,
do some research. Remember, researching how to solve a problem is often
necessary before a programmer can teach the computer how to solve
it. Use doubles for the user inputs for a, b, and c. Since there are two
solutions to a quadratic equation, output both x1 and x2.
*/

int main()
{
	try {
		cout << "Please enter coefficients of a quadratic function a, b, c:\n";
		double a, b, c;
		cin >> a >> b >> c;
		if (!cin) error("bad input");

		double D = b * b - 4 * a * c;	// discriminant
		if (D < 0) {
			error("no solutions exist");
		}
		else if (D == 0) {
			double x = -b / (2 * a);
			if (x == -0) x = 0;		// fixing awkward -0 output
			cout << "Only one root: " << x << "\n";
		}
		else {
			double x1 = (-b + sqrt(D)) / (2 * a);
			double x2 = (-b - sqrt(D)) / (2 * a);
			cout << "Roots are: " << x1 << " and " << x2 << "\n";
		}
	}
	catch (runtime_error e) {
		cout << e.what() << "\n";
		//keep_window_open("~");
	}
	catch (...) {
		cout << "exiting\n";
		//keep_window_open("~");
	}
}