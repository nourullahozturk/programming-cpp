
//
// Simple Calculator Version 01
//

/*
Problem with the previous version was when the Token returned by
get_token() is not a + or -, we just return. We don't use that
token and we don't store it anywhere for any other function to
use later. In this situation, expression() and term() functions
are eating the tokens causing a 'mysterious' logic error.

We need to store unused tokens somewhere. What we want is an
input stream that deals with tokens and that you can put an
already read token back into.

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

class Token_stream {
public:
	Token_stream();			// make a Token_stream that reads from cin
	Token get();			// get a Token
	void putback(Token t);	// put a Token back
private:
	bool full{ false };		// is there a Token in the buffer?
	Token buffer; // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;		// copy t to buffer
	full = true;	// buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get() {
	if (full) {				// do we already have a Token ready? 
		full = false;		// remove Token from buffer
		return buffer;
	}
	char ch;
	cin >> ch;

	switch (ch) {
	case '=':		// for "print"
	case 'x':		// for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token{ ch };		// let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8':case '9':
	{
		cin.putback(ch);	// put digit back into the input stream
		double val;
		cin >> val;			// read a floating-point number
		return Token('8', val);
	}
	default:
		error("Bad Token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts; // provides get() and putback()

//------------------------------------------------------------------------------

double expression();  // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

double primary()     // deal with numbers and parentheses
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
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

double term()	// deal with * and /
{
	double left = primary();
	Token t = ts.get();     // get the next Token from the Token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression()		// deal with + and –
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();     // get the next Token from the Token stream
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
{
	try {
		cout << "Welcome to our simple calculator.\n"
			<< "Please enter expressions using floating-point numbers.\n"
			<< "Available operations are +,-,*, and /.\n"
			<< "Type '=' to print the results, 'x' to exit.\n";
		double val = 0;
		while (cin) {
			Token t = ts.get();
			if (t.kind == 'x') break;	// 'x' for "quit"
			if (t.kind == '=')			// '=' for "print now"
				cout << "=" << val << '\n';
			else
				ts.putback(t);
			val = expression();
		}
		/*keep_window_open("~0");*/
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		//keep_window_open("~1");
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		keep_window_open("~2");
		return 2;
	}
}

//------------------------------------------------------------------------------