#include "std_lib_facilities.h"
/*
Simple Calculator Prototype
Problem with this version is we are doing the operations in the
wrong order.

When std::cin fails it is in a failure mode where further input
operations are ignored. You can try to correct the situation
(.clear() the failure mode + skip the letter in the input buffer)

int a,b;
cin >> a;
cin >> b; // no read
if (!cin) error("bad input");

for (char op; cin >> op;)
When you input abc cin here will read 'a' the remaining characters
will be read in the next cin operation. That's why error("second operand")
executed. Because it tries to read the next character 'b' to the rval. To
solve this we clear the buffer after reading one character, and add default
case to switch statement that throws an error when wrong operation is given
*/

//class Token {
//public:
//	char kind;
//	double value;
//};

//Token t3;		// t3 is a Token
//t3.kind = '8';	// we use digit 8 as the "kind" for numbers
//t3.value = 3.14;

//Token t1{'+'};	// initialize t1 so that t1.kind='+'
//Token t2{'8', 11.5}	// initialize t2 so that t2.kind='8' and t2.value=11.5

/*
Token get_token();	// function to read a token from cin

vector<Token> tok;

int main()
{
	while(cin){
		Token t = get_token();
		tok.push_back();
	}
	
	for(int i = 0; i < tok.size(); ++i) {
		if (tok[i].kind == '*') {	// we found a multiply!
			double d = tok[i - 1].value * tok[i + 1].value;
			// now what?
		}
	}
}
*/

int main()
{
try {
	cout << "Please enter expression (we can handle +,-,*, and /)\n";
	cout << "add an x to end expression (e.g., 1+2*3x)\n";
	int lval = 0;
	int rval;
	cin >> lval;	// read leftmost operand
	if (!cin) error("no first operand");
	for (char op; cin >> op;) {		// read operator and right-hand operand
		// repeatedly
		cin.ignore();	// if user enters a string, ignore rest of the chars
		if (op != 'x') cin >> rval;
		if (!cin) error("no second operand");
		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		case 'x':
			cout << "Result: " << lval << "\n";
			//keep_window_open();
			return 0;
		default:
			error("bad operation");
		}
	}
	error("bad expression"); // when this is executed?
}
catch (runtime_error& e) {
	cout << e.what() << "\n";
	//keep_window_open("~");
}
catch (...) {
	cout << "exiting\n";
	//keep_window_open("~");
}
}