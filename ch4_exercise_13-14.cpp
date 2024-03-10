#include "std_lib_facilities.h"

/*
13. Create a program to find all the prime numbers between 1 and 100. There
is a classic method for doing this, called the “Sieve of Eratosthenes.” If
you don’t know that method, get on the web and look it up. Write your
program using this method.

14. Modify the program described in the previous exercise to take an input
value max and then find all prime numbers from 1 to max.
*/

/*
referencing vector<bool> values is not working with
"std_lib_facilities.h" but it's working with #include <vector>
*/

int main()
{
	cout << "Please enter a max value: \n";
	int max;
	cin >> max;

	// VERSION 2

	vector<int> is_prime(max + 1, 1); // 0 - 100, last element included
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= max; ++i)
		if (is_prime[i] && i * i <= max)
			for (int j = i * i; j <= max; j += i)
				is_prime[j] = 0;

	cout << "Primes:\n";
	for (int i = 0; i <= max; ++i)
		if(is_prime[i]) cout << i << "\n";

	// VERSION 1

	//vector<int> composites(max, 0); // holds 0 or 1 for all numbers between 2 - 100
	//
	//// initialize all elements to not composite (0: composite, 1: not composite)
	//for (int i = 2; i <= max; ++i)
	//	if (i % 2 == 0) composites[i - 2] = 1;
	//
	//vector<int> primes;
	//for (int i = 2; i <= max; ++i) {
	//	if (composites[i - 2] == 1) continue; // number is composite
	//	for (int j = i; j <= max; ++j) // number is not composite (it's a prime number)
	//		if (j % i == 0) composites[j - 2] = 1; // mark that number and it's
	//											   // multiples as composites
	//	primes.push_back(i);
	//}

	//cout << "Primes:\n";
	//for (int i : primes) cout << i << "\n";
}
