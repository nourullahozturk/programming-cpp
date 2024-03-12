#include "std_lib_facilities.h"
/*
// Logic Errors

Program calculates wrong results given the inputs below:

76.5, 73.5, 71.0, 73.6, 70.1, 73.5, 77.6, 85.3,
88.5, 91.7, 95.9, 99.2, 98.2, 100.6, 106.3, 112.4,
110.2, 103.6, 94.9, 91.7, 88.4, 85.2, 85.4, 87.7

High temperature: 112.4
Low temperature: 0.0
Average temperature: 89.2
*/


int main()
{
	vector<double> temps;

	double sum = 0;
	double high_temp = -460; // min possible temp is −459.67 F
	double low_temp = 1000; // max possible temp is infinite.
	int no_of_temps = 0;

	for (double temp; cin >> temp;) {
		++no_of_temps;
		sum += temp;
		if (temp > high_temp) high_temp = temp;
		if (temp < low_temp) low_temp = temp;
	}

	cout << "High temperature: " << high_temp << "\n";
	cout << "Low temperature: " << low_temp << "\n";
	cout << "Average temperature: " << sum / no_of_temps << "\n";
}