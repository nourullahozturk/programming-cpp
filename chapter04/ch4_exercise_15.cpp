#include "std_lib_facilities.h"
/*
15. Write a program that takes an input value n and then finds the first n
primes.
*/

vector<int> primes;

bool is_prime(int n)
{
	for (int i = 0; i < primes.size() / 2; ++i)
		if (n % primes[i] == 0) return false;
	return true;
}

int main()
{
try {
	cout << "How many primes do you want to compute?\n";
	int n;
	cin >> n;

	for (int i = 2; n != primes.size(); ++i) {
		if (is_prime(i)) primes.push_back(i);
	}

	cout << "Primes: \n";
	for (int i = 0; i < primes.size(); ++i)
		cout << i + 1 << ": " << primes[i] << "\n";
}
catch (runtime_error e) {
	cout << e.what() << "\n";
	keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	keep_window_open("~");
}
}