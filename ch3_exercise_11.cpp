#include "std_lib_facilities.h"
/*
11. Write a program that prompts the user to enter some number of pennies
(1-cent coins), nickels (5-cent coins), dimes (10-cent coins), quarters
(25-cent coins), half dollars (50-cent coins), and one-dollar coins
(100-cent coins). Query the user separately for the number of each size
coin, e.g., “How many pennies do you have?” Then your program should
print out something like this:
	You have 23 pennies.
	You have 17 nickels.
	You have 14 dimes.
	You have 7 quarters.
	You have 3 half dollars.
	The value of all of your coins is 573 cents.
Make some improvements: if only one of a coin is reported, make the
output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes).
Also, report the sum in dollars and cents, i.e., $5.73 instead of 573 cents.
*/
int main()
{
	constexpr double nickles_to_cent = 5;
	constexpr double dimes_to_cent = 10;
	constexpr double quarters_to_cent = 25;
	constexpr double half_dollars_to_cent = 50;
	constexpr double dollars_to_cent = 100;

	int pennies, nickels, dimes, quarters, half_dollars, dollars;
	cout << "How many pennies do you have?\n";
	cin >> pennies;
	cout << "How many nickels do you have?\n";
	cin >> nickels;
	cout << "How many dimes do you have?\n";
	cin >> dimes;
	cout << "How many quarters do you have?\n";
	cin >> quarters;
	cout << "How many half dollars do you have?\n";
	cin >> half_dollars;
	cout << "How many dollars do you have?\n";
	cin >> dollars;

	int total_cents = pennies + nickels * nickles_to_cent
		+ dimes * dimes_to_cent + quarters * quarters_to_cent
		+ half_dollars * half_dollars_to_cent + dollars
		* dollars_to_cent;
	double total_dollars = double(total_cents) / 100;

	if (pennies == 0){}
	else if (pennies == 1) cout << "You have 1 penny.\n";
	else cout << "You have " << pennies << " pennies.\n";

	if (nickels == 0) {}
	else if (nickels == 1) cout << "You have 1 nickel.\n";
	else cout << "You have " << nickels << " nickels.\n";

	if (dimes == 0) {}
	else if (dimes == 1) cout << "You have 1 dime.\n";
	else cout << "You have " << dimes << " dimes.\n";

	if (quarters == 0) {}
	else if (quarters == 1) cout << "You have 1 quarter.\n";
	else cout << "You have " << quarters << " quarters.\n";

	if (half_dollars == 0) {}
	else if (half_dollars == 1) cout << "You have 1 half dollar.\n";
	else cout << "You have " << half_dollars << " half dollars.\n";

	if (dollars == 0) {}
	else if (dollars == 1) cout << "You have 1 dollar.\n";
	else cout << "You have " << dollars << " dollars.\n";
		
	cout << "The value of all of your coins is $" << total_dollars;
	if (total_cents == 1) cout << " (1 cent).\n";
	else cout << " (" << total_cents << "cents).\n";
}