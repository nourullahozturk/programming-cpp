
//
// Simple Calculator Version 00
// This is the first working version of the simple calculator program.
// It has a 'mysterious' error that causes it to 'eat' some of the Tokens
// given. Consequently, produces wrong results.
//

/*
expression grammar rules for the program

Expression:
	Term
	Expression "+" Term // addition
	Expression "–" Term // subtraction
Term:
	Primary
	Term "*" Primary // multiplication
	Term "/" Primary // division
	Term "%" Primary // remainder (modulo)
Primary:
	Number
	"(" Expression ")" // grouping
Number:
	floating-point-literal
*/


#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
		//not yet   case ';':    // for "print"
		//not yet   case 'q':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

double expression();  // read and evaluate a Expression

//------------------------------------------------------------------------------

double term();        // read and evaluate a Term

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
	Token t = get_token();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = get_token();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

int main()
{
try {
	while (cin)
		cout << expression() << '\n';
	keep_window_open("~0");
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("~1");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~2");
	return 2;
}
}

//------------------------------------------------------------------------------

double expression()
// the third version
// We removed the mention of expression() within expression() and
// replaced it with a loop. In other words, we translated the
// Expression in the grammar rules for Expression into a loop
// looking for a Term followed by + or a -.
{
	double left = term();      // read and evaluate a Term
	Token t = get_token();     // get the next token
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = get_token();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = get_token();
			break;
		default:
			return left;       // finally: no more + or -: return the answer
		}
	}
}


/*
double expression()
// expression function
// the first version
{
	double left = expression();
	Token t = get_token();
	switch (t.kind) {
	case '+':
		return left + term();
	case '-':
		return left - term();
	default:
		return left;
	}
}
// Problem with this version is it's calling itself
// at the first line, therefore, causes an infinite
// recursion problem.
*/

/*
// To solve the issue with the first version we use term() instead
// of an expression() to get an initial value for the 'left' variable
// Every term is an Expression, but not every Expression is a Term;
// that is, we could start looking for a Term and look for a full
// Expression only if we found a + or -.

double expression()
// expression function
// the second version
{
	double left = term();
	Token t = get_token();
	switch (t.kind) {
	case '+':
		return left + expression();
	case '-':
		return left - expression();
	default:
		return left;
	}
}
// Problem with this version is it's implements this grammar;
// Expression:
//		Term
//		Term '+' Expression
//		Term '-' Expression
//instead of this grammar;
// Expression:
//		Term
//		Expression '+' Term
//		Expression '-' Term
// So, it evaluates expressions right-to-left. Therefore, it
// produces wrong results for expressions like 1-2-3.
*/

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	Token t = get_token();     // get the next token

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = get_token();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = get_token();
			break;
		}
		default:
			return left;
		}
	}
}

//------------------------------------------------------------------------------