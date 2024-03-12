#include "std_lib_facilities.h"

class Bad_area {}; // a type specifically reporting errors from area()

// calculate area of a rectangle;
// throw a Bad_area exception in case of a bad argument
int area(int length, int width)
{
	//if (length <= 0 || width <= 0) throw Bad_area{};
	if (length <= 0 || width <= 0) error("bad argument");
	return length * width;
}

// calculate area of a framed rectangle;
// return -1 to indicate a bad argument (not necessary since area throws exceptions)
int framed_area(int x, int y)
{
	constexpr int frame_width = 2;
	//if (x - frame_width <= 0 || y - frame_width <= 0) return -1;
	return area(x - frame_width, y - frame_width);
}

int main()
{
try {
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = area1 / area3;

	// Range errors

	//vector<int> v; // a vector of ints
	//for (int x; cin >> x; )
	//	v.push_back(x); // set values
	//for (int i = 0; i <= v.size(); ++i) // print values
	//	cout << "v[" << i << "] == " << v[i] << '\n';
}
//catch (Bad_area) {
//	cout << "Oops! bad arguments to area()\n";
//	keep_window_open("~");
//}
//catch (runtime_error& e) {
//	cerr << "runtime error: " << e.what() << '\n';
//	keep_window_open();
//	return 1; // 1 indicates failure
//}
//catch (out_of_range) {
//	cerr << "Oops! Range error\n";
//	return 1;
//}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1; // 1 indicates failure
}
catch (...) { // catch all other exceptions
	cerr << "Exception: something went wrong\n";
	return 2;
}
}