#include "StudentGrades.h"
#include <iostream>
using namespace std;

StudentGrades::StudentGrades(string last, string first) {
  lastName = last;
  firstName = first;
}

string StudentGrades::getName() {
  string name = lastName + ", " + firstName;
  return name;
}
	
void StudentGrades::enterHomeworkGrades() {
  cout << "Enter ten homework grades: " << endl;
  for (int i = 0; i < 10; i++) {
    cout << "Enter score: ";
    cin >> homework[i];
  }
}

void StudentGrades::enterQuizGrades() {
  cout << "Enter ten quiz grades: " << endl;
  for (int i = 0; i < 10; i++) {
    cout << "Enter score: ";
    cin >> quizzes[i];
  }
}

void StudentGrades::enterExamGrades() {
  cout << "Enter four exam grades: " << endl;
  for (int i = 0; i < 4; i++) {
    cout << "Enter score: ";
    cin >> exams[i];
  }
}

void StudentGrades::printGrades() {
  cout << "Homework Grades: " << endl;
  for (int i = 0; i < 10; i++)
    cout << homework[i] << endl;
  cout << endl;
    
  cout << "Quiz Grades: " << endl;
  for (int i = 0; i < 10; i++)
    cout << quizzes[i] << endl;
  cout << endl;

  cout << "Exam Grades: " << endl;
  for (int i = 0; i < 4; i++)
    cout << exams[i] << endl;
  cout << endl;
}

double StudentGrades::getHomeworkAverage() {
  double total = 0;
  for (int i = 0; i < 10; i++)
	  total += homework[i];

  return total / 10;
}
