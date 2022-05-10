#include <iostream>
#include "Circle.h"
using namespace std;

void printCircles(Circle** circleArr, int numCircles);

int main()
{
	int howManyCircles = 0;
	int radius = 0;

	cout << "How many circles would you like to make?" << endl;
	cin >> howManyCircles;

	Circle** circles = new Circle * [howManyCircles];

	for (int i = 0; i < howManyCircles; i++)
	{
		cout << "What radius for circle " << i << "?" << endl;
		cin >> radius;
		circles[i] = new Circle(radius);
	}

	cout << endl;

	printCircles(circles, howManyCircles);

	// delete individual circles
	for (int i = 0; i < howManyCircles; i++)
	{
		delete circles[i];
		circles[i] = nullptr;
	}

	delete[] circles;

	return 0;
}

void printCircles(Circle** circleArr, int numCircles)
{
	for (int i = 0; i < numCircles; i++)
	{
		cout << "Circle " << i << endl;
		cout << "\t" << circleArr[i]->circumference() << endl;
		cout << "\t" << circleArr[i]->area() << endl;
		cout << endl;
	}
}