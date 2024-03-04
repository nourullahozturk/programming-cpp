#include "std_lib_facilities.h"

int main()
{
	// Taking inputs
	cout << "Enter the name of the person you want to write to:\n";
	string first_name;
	cin >> first_name;

	cout << "Enter your friend's name:\n";
	string friend_name;
	cin >> friend_name;

	cout << "Enter the sex of your friend (m for male, f for female):\n";
	char friend_sex;
	cin >> friend_sex;

	cout << "Enter the age of the recipient:\n";
	int age;
	cin >> age;

	if (age <= 0 || age >= 110)
		simple_error("You're kidding!");

	// Printing the letter
	cout << "Dear " << first_name << ", \n"
		<< "    How are you? I am fine. I miss you so much.\n"
		<< "Have you seen " << friend_name << " lately?\n";
	if (friend_sex == 'm')
		cout << "If you see " << friend_name << " please ask him to call me\n";
	if (friend_sex == 'f')
		cout << "If you see " << friend_name << " please ask her to call me\n";
	cout << "I hear you just had a birthday and you are "
		<< age << " years old.\n";
	if (age < 12)
		cout << "Next year you will be " << age + 1 << ".\n";
	if (age == 17)
		cout << "Next year you will be able to vote.\n";
	if (age > 70)
		cout << "I hope you are enjoying retirement.\n";
	cout << "Yours sincerely,\n\n\n";
	cout << "Nurullah Ozturk\n";
}