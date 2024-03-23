// Nurullah Ozturk 3/23/2024
// Chapter 6 Exercise 8

#include "std_lib_facilities.h"

/*
8. Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use
four letters rather than four digits.

Chapter 5, exercise 12-13 tasks were:

12. Implement a little guessing game called (for some obscure reason) “Bulls
and Cows.” The program has a vector of four different integers in the
range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover
those numbers by repeated guesses. Say the number to be guessed is 1234
and the user guesses 1359; the response should be “1 bull and 1 cow”
because the user got one digit (1) right and in the right position (a bull)
and one digit (3) right but in the wrong position (a cow). The guessing
continues until the user gets four bulls, that is, has the four digits correct
and in the correct order.

13. The program is a bit tedious because the answer is hard-coded into the
program. Make a version where the user can play repeatedly (without
stopping and restarting the program) and each game has a new set of
four digits. You can get four random digits by calling the random number
generator randint(10) from std_lib_facilities.h four times. You will note
that if you run that program repeatedly, it will pick the same sequence of
four digits each time you start the program. To avoid that, ask the user
to enter a number (any number) and call srand(n) where n is the number
the user entered before calling randint(10). Such an n is called a seed, and
different seeds give different sequences of random numbers.
*/

vector<char> v(4);
vector<char> g(4);	// user's guess
vector<char> letters = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main()
{
try {
	// Initializing the game
	cout << "Bulls and Cows Game\n";
	cout << "Please enter a 'seed' number to play:\n";
	int seed;
	cin >> seed;
	if (!cin) error("bad input: seed must be an integer");
	srand(seed);
	for (int i = 0; i < v.size(); ++i) v[i] = letters[rand() % 26];

	// Starting the game loop
	cout << "Enter your guess of a 4-letter string(e.g. abcd):\n";
	string s;
	while (cin >> s) { // Game loop
		if (s.size() != v.size()) { // check that user entered a 4-letter string
			cout << "The string must have four characters\n";
			continue;
		}
		// get a 4-letter string from the user, read each letter to a vector
		bool is_error = true;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < letters.size(); ++j) {
				if (s[i] == letters[j]) {
					g[i] = letters[j];
					is_error = false;
					break;
				}
			}
			if (is_error) error("You have to enter a valid letter (e.g. a b c..)");
			else is_error = true; // reset error flag for the next iteration
		}

		// compare both vectors to apply game logic 
		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < g.size(); ++i) { // for every letter that user has guessed
			for (int j = 0; j < v.size(); ++j) {
				if (g[i] == v[j]) {		// check whether it is equal to a letter of the actual string
					if (i == j) ++bulls;	// check whether it is also in the right place as with
					// the letter of the actual string	
					else ++cows;
				}
			}
		}

		// print the result
		if (bulls == 4) {
			cout << bulls << " bulls. You guessed it correct!\n"
				<< "Starting a new game...\nMake a guess:\n";
			for (int i = 0; i < v.size(); ++i) v[i] = letters[rand() % 26];
		}
		else cout << bulls << " bull and " << cows << " cow\n";
	}
}
catch (exception& e) {
	cerr << e.what() << endl;
	//keep_window_open("~1");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	//keep_window_open("~2");
	return 2;
}
}