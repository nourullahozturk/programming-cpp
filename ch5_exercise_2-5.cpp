#include "std_lib_facilities.h"
/*
2. The following program takes in a temperature value in Celsius and converts
it to Kelvin. This code has many errors in it. Find the errors, list
them, and correct the code.

3. Absolute zero is the lowest temperature that can be reached; it is –273.15°C,
or 0K. The above program, even when corrected, will produce erroneous
results when given a temperature below this. Place a check in the
main program that will produce an error if a temperature is given below
–273.15°C.

4. Do exercise 3 again, but this time handle the error inside ctok().

5. Add to the program so that it can also convert from Kelvin to Celsius.
*/

double ctok(double c) 
// converts Celsius to Kelvin;
// pre-conditions: celcius is greater than or equal to -273.15 degrees
// post-condition: returns a positive value or a zero
{
	if (c <= -273.15) error("temperature cannot be below -273.15 degrees celcius");
	double k = c + 273.15;
	if (k < 0) error("ctok() post-condition failed");
	return k;
}

double ktoc(double k)
// converts Kelvin to Celsius;
// pre-conditions: kelvin is greater than or equal to zero degrees
// post-condition: returns a value greater than or equal to -273.15
{
	if (k < 0) error("ktoc() pre-condition failed");
	double c = k - 273.15;
	if (c < -273.15) error("ktoc() post-condition failed");
	return c;
}

int main()
{
try {
	double c = 0; // declare input variable
	cin >> c; // retrieve temperature to input variable
	
	//if (c <= -273.15) error("temperature cannot be below -273.15 degrees celcius");
	double k = ctok(c); // convert temperature
	cout << k << '\n'; // print out temperature
	
	double k2 = 0;
	cin >> k2;
	double c2 = ktoc(k2);
	cout << c2 << '\n'; // print out temperature
}
catch (runtime_error& e) {
	cout << e.what() << "\n";
	keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}
}