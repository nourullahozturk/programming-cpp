#include "std_lib_facilities.h"

int main()
{
	// input example: She she laughed He He He because what he did did not look very very good good

	int number_of_words = 0;
	string previous = " "; // previous word; initialized to “not a word”
	string current; // current word
	while (cin >> current) { // read a stream of words
		++number_of_words; // count the word
		if (previous == current) // check if the word is the same as last
			cout << "word number: " << number_of_words
			<< " repeated: " << current << "\n";
		previous = current;
	}
}