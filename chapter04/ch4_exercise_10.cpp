#include "std_lib_facilities.h"
/*
10. Write a program that plays the game “Rock, Paper, Scissors.” If you are not
familiar with the game do some research (e.g., on the web using Google).
Research is a common task for programmers. Use a switch-statement to
solve this exercise. Also, the machine should give random answers (i.e.,
select the next rock, paper, or scissors randomly). Real randomness is too
hard to provide just now, so just build a vector with a sequence of values
to be used as “the next value.” If you build the vector into the program,
it will always play the same game, so maybe you should let the user enter
some values. Try variations to make it less easy for the user to guess
which move the machine will make next.
*/

string produce_result(int a, int b) {
	if (a == b) return "Draw";
	if ((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1)) return "You Lose";
	if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2)) return "You Win!";
}

void print_moves(int a, int b) {
	string str1, str2;
	if (a == 1) str1 = "Rock";
	if (a == 2) str1 = "Paper";
	if (a == 3) str1 = "Scissor";
	if (b == 1) str2 = "Rock";
	if (b == 2) str2 = "Paper";
	if (b == 3) str2 = "Scissor";

	cout << "Your move: " << str1 << "   Computer's move: " << str2 << "\n";
}

vector<int> reverse_vector(vector<int> m) {
	int temp;
	for (int i = 0; i < m.size() / 2; ++i) {
		temp = m[i];
		m[i] = m[m.size() - 1 - i];
		m[m.size() - 1 - i] = temp;
	}
	return m;
}

vector<int> fill_vector(vector<int> m) {
	int number;
	cout << "Enter some random values from 1, 2, or 3: \n";
	for (int i = 0; i < 3; ++i) {
		cin >> number;
		m.push_back(number);
	}
	return m;
}

int main()
{
	vector<int> moves;

	// fill the vector with user inputs
	moves = fill_vector(moves);
	
	// reverse the elements of the vector
	moves = reverse_vector(moves);

	cout << "Game begins!\n" << "Please enter your move as a number"
		<< " (1 for rock, 2 for paper, 3 for scissor) : \n";

	int move;
	for (int i = 0; i < moves.size(); ++i) {
		cin >> move;
		print_moves(move, moves[i]);
		cout << "Result: " << produce_result(move, moves[i]) << "\n";
	}
}