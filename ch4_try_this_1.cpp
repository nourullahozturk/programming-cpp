#include "std_lib_facilities.h"

int main()
{
	constexpr double dollar_per_yen = 0.0067;
	constexpr double dollar_per_euro = 1.09;
	constexpr double dollar_per_pounds = 1.27;

	double amount = 1;

	char unit = 0;
	cout << "Please enter an amount followed by a unit(y for yen, e for euro, p for pounds):\n";
	cin >> amount >> unit;

	if (unit == 'y')
		cout << amount << "yen == " << amount * dollar_per_yen << "dollars\n";
	else if (unit == 'e')
		cout << amount << "euro == " << amount * dollar_per_euro << "dollars\n";
	else if (unit == 'p')
		cout << amount << "pounds == " << amount * dollar_per_pounds << "dollars\n";
	else
		cout << "Sorry, I don't know a unit called " << unit << "\n";
}
