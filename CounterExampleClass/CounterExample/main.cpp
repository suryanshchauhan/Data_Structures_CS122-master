#include <iostream>
#include "Counter.h"

using namespace std;

int main() {
  Counter ctr; // In Java, this would be   Counter ctr = new Counter();
  cout << ctr.getCount() << endl;

  ctr.increaseBy(3);
  cout << ctr.getCount() << endl;

  ctr.increaseBy(5);
  cout << ctr.getCount() << endl;

  return 0;
}
