#include "std_lib_facilities.h"

int area(int length, int width);

int main()
{
	int s1 = area(7; // syntax error : missing ')' before ';'
	int s2 = area(7) // error: ; missing
	Int s3 = area(7); // error: Int is not a type
	int s4 = area('7); // error: non-terminated character ( ' missing)

	int x0 = arena(7); // identifier "arena" is undefined
	int x7 = area(7); // too few arguments in function call
	int x2 = area("seven", 2); // argument of type "const char *" is incompatible with parameter of type "int"
}