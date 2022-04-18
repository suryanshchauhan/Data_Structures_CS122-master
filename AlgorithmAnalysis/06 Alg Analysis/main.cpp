// Algorithm Analysis
// Steven Bogaerts

#include <iostream>
#include <string>

using namespace std;

int f1(int n) {
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += i;
	return sum;
}

int f2(int n) {
	int total = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			total += i*j;
	return total;
}

void f3(int n) {
	cout << "Bam!" << endl;
}

// -------------------------------------------------------------

int g1(int n) {
	int sum = 0;
	int prod = 1;

	for(int i = 1; i < n; i++) {
		sum += i;
		prod *= i;
	}

	return sum + prod;
}

void g2(int n) {
	string s, d, c;
	for(int i = 0; i < n; i++) {
		s = "";
		for(int j = 0; j < n; j++)
			s += (char) j;

		d = "";
		for(int j = n-1; j >= 0; j--)
			d += (char) (i - j);

		c = "";
		for(int j = 0; j < n; j++)
			c += (char) (s[j] + d[j]);

		cout << c << endl;
	}
}

void g3(int n) {
	cout << "Hello!" << endl;
	cout << "Hello!" << endl;
	cout << "Hello!" << endl;
}

// -----------------------------------------------------

void h1(int n) {
	int prod = 1;
	int result;
	for(int i = 0; i < n; i++) {
		prod = prod * i;
		result = f1(i);  // this is i work
	}
}

void h2(int n) {
	int sum;
	int prod = 1;
	for(int i = 0; i < n; i++) {
		prod *= i;

		sum = 0;
		for(int v = 0; v < i; v++)
			sum += v;
		cout << sum << endl;
	}
}

// -----------------------------------------------------

int main() {
	// Choose one or more of the following to run.
	cout << f1(5) << endl;
	cout << f2(5) << endl;
	f3(5);

	cout << g1(5) << endl;
	g2(5);
	g3(5);

	h1(5);
	h2(5);

	return 0;
}