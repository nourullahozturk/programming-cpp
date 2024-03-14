#include "std_lib_facilities.h"
/*
7. Quadratic equations are of the form 
	ax^2 + bx + c = 0
To solve these, one uses the quadratic formula:
	x = (-b +- sqrt(b^2 - 4ac)) / 2a
There is a problem, though: if b2–4ac is less than zero, then it will fail.
Write a program that can calculate x for a quadratic equation. Create a
function that prints out the roots of a quadratic equation, given a, b, c.
When the program detects an equation with no real roots, have it print
out a message. How do you know that your results are plausible? Can
you check that they are correct?
*/

vector<double> quadratic_solver(double a, double b, double c)
{
	double D = b * b - 4 * a * c;
	if (D < 0) error("no real roots");

	double sol1 = (-b + sqrt(D)) / (2 * a);
	double sol2 = (-b - sqrt(D)) / (2 * a);

	vector<double> solutions;
	solutions.push_back(sol1);
	solutions.push_back(sol2);

	return solutions;
}

int main()
{
try {

	cout << "Please enter coefficients a, b, and c of the quadratic equation\n";
	double a, b, c;
	cin >> a >> b >> c;

	vector<double> sols(2);
	sols = quadratic_solver(a, b, c);

	cout << "solution 1: " << sols[0] << "\nsolution 2: " << sols[1] << "\n";
}
catch (runtime_error& e) {
	cout << e.what() << "\n";
}
catch (...) {
	cout << "exiting\n";
}
}