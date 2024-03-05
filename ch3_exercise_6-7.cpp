#include "std_lib_facilities.h"
/*
6. Write a program that prompts the user to enter three integer values, and
then outputs the values in numerical sequence separated by commas. So,
if the user enters the values 10 4 6, the output should be 4, 6, 10. If two
values are the same, they should just be ordered together. So, the input
4 5 4 should give 4, 4, 5.

7. Do exercise 6, but with three string values. So, if the user enters the values
Steinbeck, Hemingway, Fitzgerald, the output should be Fitzgerald,
Hemingway, Steinbeck.
*/

int main()
{
	cout << "Please enter three integers: \n";

	double val1, val2, val3;
	cin >> val1 >> val2 >> val3;
	double temp;

	if (val1 > val2) {
		temp = val2;
		val2 = val1;
		val1 = temp;
	}
	if (val2 > val3) {
		temp = val3;
		val3 = val2;
		val2 = temp;
	}
	if (val1 > val2) {
		temp = val2;
		val2 = val1;
		val1 = temp;
	}
	cout << val1 << ", " << val2 << ", " << val3 << "\n";
}	

//int main()
//{
//	cout << "Please enter three strings: \n";
//
//	string str1, str2, str3;
//	cin >> str1 >> str2 >> str3;
//	string temp;
//
//	if (str1 > str2) {
//		temp = str2;
//		str2 = str1;
//		str1 = temp;
//	}
//	if (str2 > str3) {
//		temp = str3;
//		str3 = str2;
//		str2 = temp;
//	}
//	if (str1 > str2) {
//		temp = str2;
//		str2 = str1;
//		str1 = temp;
//	}
//	cout << str1 << ", " << str2 << ", " << str3 << "\n";
//}