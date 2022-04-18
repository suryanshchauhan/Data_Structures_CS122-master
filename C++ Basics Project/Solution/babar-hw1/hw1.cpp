#include <iostream>
#include <string>
using namespace std;

void hey()
//The function prompts the user to enter a name, greets the user by name, and then prints a goodbye message.
{   string a;
	cout << "Please enter your name:";
	cin >> a;

	cout << "Hello, " << a << "!" << endl;

	cout << "See ya." << endl;
}

void arrayStats()
//The function prints the average value and each individual value minus the average.
{
	double a;
	double sum = 0;
	double avg;
	int indexNumber;
	double array[5];

	cout << "Please enter 5 numbers:";
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		array[i] = a;
	}

	for (int i = 0; i < 5; i++)
	{
		sum = sum + array[i];
	}
	avg = sum / 5;

	cout << "The average is: " << avg << endl;

	cout << "Here are the differences from the average:" << endl;

	for (int i = 0; i < 5; i++)
	{
		indexNumber = i;
		cout << "For the value at index " << indexNumber << " subtracting the average gives: " << array[i] - avg << endl;
	}
}

void testLoops()
//Prints all even integers in [0,n] in descending order
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	if (n % 2 == 1)
	{
		n = n - 1;
	}

	int p = n;
	cout << "   While:";
	while (p > 0)
	{
		cout << " "<< p;
		p = p - 2;		
	}

	cout << " " << endl;
    
	int z = n;
	cout << "Do While:";
	do {
		if (z > 0){
			cout << " " << z;
			z = z - 2;
		}
	} while (z > 0);

	cout << " " << endl;

	cout << "     For:";
	for (int f=n; f>0; f=f-2)
	{		
		cout << " " << f;
	}
}

int main()
{
	cout << "---------- Exercise 1 ----------" << endl;
	hey();
	cout << "---------- Exercise 2 ----------" << endl;
	arrayStats();
	cout << "---------- Exercise 3 ----------" << endl;
	testLoops();
	return 0;
}