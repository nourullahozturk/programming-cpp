#include "std_lib_facilities.h"

// write out a table of characters with their corresponding integer values
// The character 'b' is char('a'+1), 'c' is char('a'+2), etc.
int main()
{

	// WHILE LOOP
	// Lowercase letters
	int i = 0;
	while (i < 26) {
		cout << char('a' + i) << "\t" << 'a' + i << "\n";
		++i;
	}

	// FOR LOOP
	// Digits
	for (int i = 0; i < 10; i++) 
		cout << char('0' + i) << "\t" << '0' + i << "\n";
	cout << "-----------------------------------\n";
	// Uppercase letters
	for (int j = 0; j < 26; j++) 
		cout << char('A' + j) << "\t" << 'A' + j << "\n";
	cout << "-----------------------------------\n";
	// Lowercase letters
	for (int k = 0; k < 26; k++) 
		cout << char('a' + k) << "\t" << 'a' + k << "\n";
}