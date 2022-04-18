#include "Counter.h"

Counter::Counter() {
  count = 0;
}


int Counter::getCount() {
  return count;
}


void Counter::increaseBy(int x) {
  count += x;
}
