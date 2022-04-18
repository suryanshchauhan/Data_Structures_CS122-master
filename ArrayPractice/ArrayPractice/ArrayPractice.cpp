#include <iostream>
using namespace std;

int main() {
	int array[10];

	for (int i = 0; i < 10; i++) {
		array[i] = i;
	}

	cout << "Each array element + 1:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << array[i] + 1 << endl;
	}

	// so array is [0,1,2,3,4,5,6,7,8,9]

	cout << "---------------------------------------------------------" << endl;

	int sum = 0;
	int i = 0;
	while (sum < 10) {
		sum += array[i];
		i++;
	}
	cout << "The sum of the first " << i << " numbers is " << sum << "." << endl;

	cout << "---------------------------------------------------------" << endl;
	/*  // This version never ends!
    int prod = 1;
	i = 0;
	do {
		prod *= array[i];
		i++;
	} while (prod < 20);
	cout << "The product of the first " << i-1 << " numbers is " 
         << prod << "." << endl;
	*/
    
	int prod = 1;
	i = 0;
	do {
		if (array[i] != 0)
			prod *= array[i];
		i++;
	} while (prod < 20);
	cout << "The product of the first " << i << " numbers (ignoring 0's) is " << prod << "." << endl;


	return 0;
}
