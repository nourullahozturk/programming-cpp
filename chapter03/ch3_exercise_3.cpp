#include "std_lib_facilities.h"
/*
3. Write a program that doesn’t do anything, but declares a number of variables
with legal and illegal names (such as int double = 0;), so that you
can see how the compiler reacts.
*/
int main()
{
	int double = 1; // int followed by double is illegal, no variable declared before =
	int _do = 1; 
	int S$£½<d = 5; // ..:this character is not allowed in an identifier
	int 1abc;  // syntax error: 'user-defined literal'
	string str = 1; // tries to make conversion but fails
	string string = ""; // gives warning: may cause unexpected behaviour
}