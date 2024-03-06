#include "std_lib_facilities.h"
/*
3. Read a sequence of double values into a vector. Think of each value as
the distance between two cities along a given route. Compute and print
the total distance (the sum of all distances). Find and print the smallest
and greatest distance between two neighboring cities. Find and print the
mean distance between two neighboring cities.
*/
int main()
{
	vector<double> distances;
	cout << "Enter a sequence of distances between two cities: \n";
	for (double distance; cin >> distance;)
		distances.push_back(distance);

	// assumption: given distance cannot be lower than 0 and higher than 1000000
	double sum = 0, largest = -1, smallest = 1000000;
	for (double x : distances) { 
		sum += x;
		if (x > largest) largest = x;
		if (x < smallest) smallest = x;
	}

	cout << "Total distance (the sum of all distances): " << sum << "\n"
		<< "Smallest distance btw two neighboring cities: " << smallest << "\n"
		<< "Largest distance btw two neighboring cities: " << largest << "\n"
		<< "Mean distance btw two neighboring cities: " << sum / distances.size()
		<< "\n";
}