#include "std_lib_facilities.h"

int main()
{
	cout << "Enter your first name and your age:\n";
	string first_name = "???"; // "???” means “don’t know the name”
	double age = -1; // -1 means “don’t know the age”
	cin >> first_name >> age;
	cout << "Hello, " << first_name << " (age " << age * 12 << "(in months))!\n";
}