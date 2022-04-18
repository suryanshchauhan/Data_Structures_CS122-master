#include <iostream>
#include <string>

#include "StudentGrades.h"

using namespace std;

int main() {
	string first, last;

	cout << "Enter your first name: ";
	cin >> first;

	cout << "Enter your last name: ";
	cin >> last;

	StudentGrades myGrades(last, first);

	myGrades.enterHomeworkGrades();
	myGrades.enterQuizGrades();
	myGrades.enterExamGrades();

	myGrades.printGrades();

	cout << endl;

 	cout << "Your homework average is " << myGrades.getHomeworkAverage() << endl;

	return 0;
}
