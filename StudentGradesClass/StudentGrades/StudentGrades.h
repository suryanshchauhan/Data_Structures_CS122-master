#include <string>

using namespace std;

class StudentGrades {
private:
	int homework[10];
	int quizzes[10];
	int exams[4];
	string lastName;
	string firstName;

public:
	StudentGrades(string last, string first);
	string getName();
	void enterHomeworkGrades();
	void enterQuizGrades();
	void enterExamGrades();
	void printGrades();
	double getHomeworkAverage();
};
