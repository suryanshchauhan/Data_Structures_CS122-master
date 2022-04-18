#include <string>
#include <iostream>

using namespace std;

void f1(int x) {
	x = 22;
}

void f2(int &x) {
	x = 22;
}

int main() {
  cout << "----------------------------------------------" << endl;
  cout << "Calling f1" << endl;
  int x = 5;
  int y = 6;
  f1(x);
  f1(y);
  cout << x << ", " << y << endl;

  cout << "----------------------------------------------" << endl;
  cout << "Calling f2" << endl;
  x = 5;
  y = 6;
  f2(x);
  f2(y);
  cout << x << ", " << y << endl;

  return 0;
}
