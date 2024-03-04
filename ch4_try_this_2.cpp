#include "std_lib_facilities.h"

int main()
{
	constexpr double dollar_per_yen = 0.0067;
	constexpr double dollar_per_euro = 1.09;
	constexpr double dollar_per_pounds = 1.27;
	constexpr double dollar_per_yuan = 0.14;
	constexpr double dollar_per_kroner = 0.095;
	constexpr double dollar_per_tl = 0.032;

	double amount = 0;
	char unit = 0;
	cout << "Please enter an amount followed by a unit(t for tl,"
		<< " y for yen, e for euro, p for pounds, u for yuan, k for kroner):\n";
	cin >> amount >> unit;

	switch (unit) {
	case 'y':
		cout << amount << "yen == " << amount * dollar_per_yen << "dollars\n";
		break;
	case 'e':
		cout << amount << "euro == " << amount * dollar_per_euro << "dollars\n";
		break;
	case 'p':
		cout << amount << "pounds == " << amount * dollar_per_pounds << "dollars\n";
		break;
	case 'u':
		cout << amount << "yuan == " << amount * dollar_per_yuan << "dollars\n";
		break;
	case 'k':
		cout << amount << "kroner == " << amount * dollar_per_kroner << "dollars\n";
		break;
	case 't':
		cout << amount << "tl == " << amount * dollar_per_tl << "dollars\n";
		break;
	default:
		cout << "Sorry, I don't know a unit called " << unit << "\n";
		break;
	}
}