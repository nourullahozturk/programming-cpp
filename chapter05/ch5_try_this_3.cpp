#include "std_lib_facilities.h"

// Example of Error reporting

// ask user for a yes-or-no answer;
// return 'b' to indicate a bad answer (i.e. not yes or no)
char ask_user(string question)
{
	cout << question << "?(yes or no)\n";
	string answer = " ";
	cin >> answer;
	if (answer == "y" || answer == "yes") return 'y';
	if (answer == "n" || answer == "no") return 'n';
	return 'b'; // 'b' for "bad answer"
}

// calculate area of a rectangle;
// return –1 to indicate a bad argument
int area(int length, int width)
{
	if (length <= 0 || width <= 0) return -1;
	return length * width;
}

// calculate area of a framed rectangle;
// return -1 to indicate a bad argument
int framed_area(int x, int y)
{
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0) return -1;
	return area(x - frame_width, y - frame_width);
}

int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	if (area1 <= 0) error("non-positive area");

	int area2 = framed_area(1, z);
	if (area2 <= 0) error("non-positive area");

	int area3 = framed_area(y, z);
	if (area3 <= 0) error("non-poitive area");

	double ratio = double(area1) / area3;

	cout << "area1: " << area1 << "\n"
		<< "area2: " << area2 << "\n"
		<< "area3: " << area3 << "\n"
		<< "ratio: " << ratio << "\n";
}

/*
// Example of The callee deals with errors

int area(int length, int width)
{
	if (length <= 0 || width <= 0)
		error("non-positive area() argument");
	return length * width;
}

int framed_area(int x, int y)
{
	constexpr int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0)
		error("non-positive argument for area() called by framed_area()");
	return area(x - frame_width, y - frame_width);
}

int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1) / area3;

	cout << "area1: " << area1 << "\n"
		<< "area2: " << area2 << "\n"
		<< "area3: " << area3 << "\n"
		<< "ratio: " << ratio << "\n";
}
*/

/*

// Example of The caller deals with errors

int area(int length, int width)
{
	return length * width;
}

constexpr int frame_width = 2;
int framed_area(int x, int y)
{
	return area(x - 2, y - 2);
}

int main()
{
	int x = -1;
	int y = 2;
	int z = 4;

	if (x <= 0 || y <= 0) error("non-positive area() argument");
	int area1 = area(x, y);

	if (1 - frame_width <= 0 || z - frame_width <= 0)
		error("non-positive argument for area() called by framed_area()");
	int area2 = framed_area(1, z);

	if (y - frame_width <= 0 || z - frame_width <= 0)
		error("non-positive argument for area() called by framed_area()");
	int area3 = framed_area(y, z);

	double ratio = double(area1) / area3;

	cout << "area1: " << area1 << "\n"
		<< "area2: " << area2 << "\n"
		<< "area3: " << area3 << "\n"
		<< "ratio: " << ratio << "\n";
}

*/
