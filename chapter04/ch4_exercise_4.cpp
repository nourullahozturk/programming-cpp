#include "std_lib_facilities.h"
/*
4. Write a program to play a numbers guessing game. The user thinks of a
number between 1 and 100 and your program asks questions to figure
out what the number is (e.g., “Is the number you are thinking of less than
50?”). Your program should be able to identify the number after asking
no more than seven questions. Hint: Use the < and <= operators and the
if-else construct.
*/

int main()
{
	cout << "Welcome to the number guessing game!\n"
		<< "Please, enter a guess range (e.g. for numbers btw 1 and 100, enter: 1 100)\n";
	int bottom = 1, top = 100;
	cin >> bottom >> top;

	cout << "Enter the number you're thinking. I'll guess it!\n";
	int number;
	cin >> number;

	int guess = bottom + ceil(double(top - bottom) / 2);
	cout << "Is the number you are thinking of less than "
		<< guess << "? \n";

	char answer;
	while (cin >> answer) {
		switch (answer)
		{
		case 'y':
			top = guess - 1;
			guess = bottom + ceil(double(top - bottom) / 2);
			if (top == bottom) break;
			cout << "Is the number you are thinking of less than "
				<< guess << "?\n";
			break;
		case 'n':
			bottom = guess;
			guess = bottom + ceil(double(top - bottom) / 2);
			if (top == bottom) break;
			cout << "Is the number you are thinking of less than "
				<< guess << "?\n";
			break;
		default:
			break;
		}
		if (top == bottom) {
			cout << "The number you are thinking of is " << guess << "!\n";
			break;
		}
	}
}