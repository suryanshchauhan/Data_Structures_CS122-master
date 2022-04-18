#include <iostream>

using namespace std;

int main()
{
	double miles, gallons, mpg; // make this double, not int, so can easily have decimals for mpg.

	cout << "Please enter number of miles driven: ";
	cin >> miles;

	cout << "Please enter number of gallons used: ";
	cin >> gallons;
  
	mpg = miles / gallons; // anytime you use /, make sure you're getting mathematical division if that's what you want

	cout << "The average mpg is " << mpg << endl;

	if ( mpg > 30 )
		cout << "That's great!" << endl;

	return 0;
}
