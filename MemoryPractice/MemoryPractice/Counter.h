/////////////////////////////////////////////////////////////////////////
// Steven Bogaerts
/////////////////////////////////////////////////////////////////////////

// The class declaration
class Counter {
  public:
    // The constructor
    Counter();

	// A second constructor, that initializes the count based on the argument.
	Counter(int startValue);

    // Get the current count
    int getCount();

    // Add x to the count
    void increaseBy(int x);

  private:
    // The counter's value
    int count;
};
