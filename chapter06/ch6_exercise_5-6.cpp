// Nurullah Ozturk 3/21/2024
// Chapter 6 Exercise 6

#include "std_lib_facilities.h"

/*
6. Write a program that checks if a sentence is correct according to the “English”
grammar in §6.4.1. Assume that every sentence is terminated by
a full stop (.) surrounded by whitespace. For example, birds fly but the
fish swim . is a sentence, but birds fly but the fish swim (terminating dot
missing) and birds fly but the fish swim. (no space before dot) are not. For
each sentence entered, the program should simply respond “OK” or “not
OK.” Hint: Don’t bother with tokens; just read into a string using >>.

Sentence:
	Noun Verb
	Article Noun Verb
	Sentence Conjunction Sentence
Conjunction:
	"and"
	"or"
	"but"
Article:
	"The"
	"the"
Noun:
	"birds"
	"fish"
	"C++"
Verb:
	"rules"
	"fly"
	"swim"
*/

vector<string> articles;
vector<string> nouns;
vector<string> verbs;
vector<string> conjunctions;

void init()
// initialize word classes
{
	articles.push_back("The");
	articles.push_back("the");

	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");

	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");
}

bool is_article(string w)
{
	for (int i = 0; i < articles.size(); ++i)
		if (w == articles[i]) return true;
	return false;
}

bool is_noun(string w)
{
	for (int i = 0; i < nouns.size(); ++i)
		if (w == nouns[i]) return true;
	return false;
}

bool is_verb(string w)
{
	for (int i = 0; i < verbs.size(); ++i)
		if (w == verbs[i]) return true;
	return false;
}

bool is_conjunction(string w)
{
	for (int i = 0; i < conjunctions.size(); ++i)
		if (w == conjunctions[i]) return true;
	return false;
}

bool sentence()
{
	string w1;
	cin >> w1;

	if (!is_article(w1) && !is_noun(w1)) return false;

	if (is_article(w1)) {  // sentence start with an article
		string w2;
		cin >> w2;
		if (!is_noun(w2)) return false;

		string w3;
		cin >> w3;
		if (!is_verb(w3)) return false;

		string w4;
		cin >> w4;
		if (w4 == ".") return true;  // end of sentence
		if (!is_conjunction(w4)) return false;  // not end of sentence and not conjunction
		return sentence();  // look for another sentence
	}

	if (is_noun(w1)) {  // sentence start with a noun
		string w2;
		cin >> w2;
		if (!is_verb(w2)) return false;

		string w3;
		cin >> w3;
		if (w3 == ".") return true;  // end of sentence
		if (!is_conjunction(w3)) return false;  // not end of sentence and not conjunction
		return sentence();  // look for another sentence
	}

	return false;
}

int main()
{
try {
	cout << "enter a sentence of the simplified grammar (terminated by a dot):\n";
	
	init();		// initialize word tables

	while (cin) {
		bool b = sentence();
		if (b)
			cout << "OK\n";
		else
			cout << "not OK\n";
		cin.ignore(numeric_limits<streamsize>::max(),'\n');  // clear cin
		cout << "Try again: ";
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