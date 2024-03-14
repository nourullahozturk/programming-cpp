#include "std_lib_facilities.h"
/*
Find a pair of values so that the pre-condition of this version of area holds, but
the post-condition doesn’t.
*/

int area(int length, int width)
// calculate area of a rectangle;
// pre-conditions: length and width are positive
// post-condition: returns a positive value that is the area
{
	if (length <= 0 || width <= 0) error("area() pre-condition");
	int a = length * width;
	cout << a << "\n";
	if (a <= 0) error("area() post-condition");
	return a;
}

//int my_complicated_function(int a, int b, int c)
//// the arguments are positive and a < b < c
//{
//	if (!(0 < a && a < b && b < c)) // ! means “not” and && means “and”
//		error("bad arguments for mcf");
//	// . . .
//}


int main()
{
try {
	int sum;
	sum = area(2000000000, 2);
	cout << sum << "\n";
}
catch (exception& e) {
	cout << e.what() << "\n";
	return 1;
}	
}