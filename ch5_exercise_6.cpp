#include "std_lib_facilities.h"
/*
6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit
to Celsius (formula in §4.3.3). Use estimation (§5.8) to see if your
results are plausible.

F = C * 9/5 + 32
*/

double ftoc(double f)
// converts fahrenheit to celsius
// pre-condition: input must be −459.67 and above
// post-condition: return value cannot be below -273.15
{
	if (f < -459.67) error("ftoc() pre-condition failed");
	double c = (f - 32) * (5 / 9.0);
	if (c < -273.15) error("ftoc() post-condition failed");
	return c;
}

double ctof(double c)
// converts celsius to fahrenheit
// pre-condition: input cannot be below -273.15
// post-condition: return value must be −459.67 and above
{
	if (c < -273.15) error("ftoc() post-condition failed");
	double f = c * (9.0 / 5) + 32;
	if (f < -459.67) error("ftoc() pre-condition failed");
	return f;
}


int main()
{
try {
	cout << "Please enter a temperature value followed by C or F\n";
	double temp;
	char deg;
	cin >> temp >> deg;

	if (deg == 'c' || deg == 'C')
		cout << temp << "C is " << ctof(temp) << "F\n";
	if(deg == 'f' || deg == 'F')
		cout << temp << "F is " << ftoc(temp) << "C\n";
}
catch (runtime_error& e) {
	cout << e.what() << "\n";
	keep_window_open();
}
catch (...) {
	cout << "exiting\n";
	keep_window_open();
}
}