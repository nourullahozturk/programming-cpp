#include "std_lib_facilities.h"
/*
11. Create a program to find all the prime numbers between 1 and 100. One
way to do this is to write a function that will check if a number is prime
(i.e., see if the number can be divided by a prime number smaller than
itself) using a vector of primes in order (so that if the vector is called
primes, primes[0]==2, primes[1]==3, primes[2]==5, etc.). Then write a
loop that goes from 1 to 100, checks each number to see if it is a prime,
and stores each prime found in a vector. Write another loop that lists the
primes you found. You might check your result by comparing your vector
of prime numbers with primes. Consider 2 the first prime.
*/

vector<int> primes;

bool is_prime(int n) {
	for (int i = 0; i < primes.size(); ++i)
		if (n % primes[i] == 0) return false;
	return true;
}

int main()
{
try {
	cout << "Enter up to which value that prime numbers will be calculated\n";
	int max;
	cin >> max;

	clock_t startTime = clock();

	primes.push_back(2); // first prime number is 2

	// Find prime numbers between 3 and 100
	for (int i = 3; i <= max; ++i)
		if (is_prime(i)) primes.push_back(i);

	// Print those prime numbers
	cout << "Primes:\n";
	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << "\n";

	cout << double(clock() - startTime) / (double)CLOCKS_PER_SEC << " seconds." << "\n";

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