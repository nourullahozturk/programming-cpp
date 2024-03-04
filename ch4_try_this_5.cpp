#include "std_lib_facilities.h"

// Write a simple dictionary program that "bleeps" out words that you don't like
int main()
{
	vector<string> words;
	for (string word; cin >> word;)
		words.push_back(word);
	cout << "Number of words: " << words.size() << "\n";

	sort(words);

	string disliked = "broccoli";

	for (int i = 0; i < words.size(); i++) {
		if (i == 0 || words[i - 1] != words[i]) {
			if (words[i] == disliked) { cout << "BLEEP\n"; }
			else { cout << words[i] << "\n"; }
		}
	}	
}