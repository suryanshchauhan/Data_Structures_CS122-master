#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
  cout << "------------------------------------" << endl;
  Counter ctr;
  cout << ctr.getCount() << endl;

  ctr.increaseBy(3);
  cout << ctr.getCount() << endl;

  cout << "------------------------------------" << endl;
  Counter ctr2(15); // This is the syntax many people prefer.
  cout << ctr2.getCount() << endl;

  ctr2.increaseBy(3);
  cout << ctr2.getCount() << endl;

  cout << "------------------------------------" << endl;
  Counter ctr3 = 15; // Many people (myself included) don't like this syntax. I recommend the approach above.
  cout << ctr3.getCount() << endl;

  ctr3.increaseBy(3);
  cout << ctr3.getCount() << endl;

  return 0;
}
