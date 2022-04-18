// The class declaration
class Counter {
  public:
    // The constructor
    Counter();

    // Get the current count
    int getCount();

    // Add x to the count
    void increaseBy(int x);

  private:
    // The counter's value
    int count;
};
