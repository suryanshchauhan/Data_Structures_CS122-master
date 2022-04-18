/////////////////////////////////////////////////////////////////////////
// Steven Bogaerts
/////////////////////////////////////////////////////////////////////////

#include "Counter.h"

Counter::Counter() {
  count = 0;
}

Counter::Counter(int startValue) {
  count = startValue;
}

int Counter::getCount() {
  return count;
}

void Counter::increaseBy(int x) {
  count += x;
}
