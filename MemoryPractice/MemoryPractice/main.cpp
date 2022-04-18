/////////////////////////////////////////////////////////////////////////
// Steven Bogaerts
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "Counter.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void checkMemoryAddress() {
	cout << "================ checkMemoryAddress ================" << endl;
	cout << "Note that the addresses will typically be different each time you run the code!" << endl;

	int i = 5;
	double d = 6.1;
	string s = "sup";
	Counter c(7);

	cout << "i is at " << &i << endl;
	cout << "d is at " << &d << endl;
	cout << "s is at " << &s << endl;
	cout << "c is at " << &c << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pointers() {
	cout << "================ pointers ================" << endl;

	int a = 1;

	int* b = &a; // This is how we'll do it.
	int * c = &a;
	int *d = &a;

	cout << b << endl << c << endl << d << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dereferencing() {
	cout << "================ dereferencing ================" << endl;

	int a = 1;
	int* p = &a;

	cout << p << endl;  // the address of a (the address pointed to)
	cout << *p << endl; // the value in a (the value at the address pointed to)
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pointerPractice() {
	cout << "================ pointerPractice ================" << endl;

	int a = 1;
	int* pa = &a;
	cout << "1) " << *pa << endl;

	int* px = pa;
	cout << "2) " << *px << endl;

	a = a + 1;
	cout << "3) " << a << " " << *pa << " " << *px << endl;

	*px = (*px) + 10; // Just use parentheses so there's no doubt.
	cout << "4) " << a << " " << *pa << " " << *px << endl;

	int b = 5;
	px = &b;
	cout << "5) " << a << " " << *pa << " " << *px << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pointerPractice2() {
	cout << "================ pointerPractice2 ================" << endl;

	int a = 5;
	int* p1 = &a;
	int* p2 = p1;

	a = (*p1) + (*p2) + a;
	cout << a << " " << *p1 << " " << *p2 << endl;

	int b = a;
	b++;
	cout << a << " " << *p1 << " " << *p2 << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dynamicMemoryAllocation() {
	cout << "================ dynamicMemoryAllocation ================" << endl;
	int* p = new int;

	*p = 5;
	cout << p << " " << *p << endl;

	delete p; // Don't forget this!!! Otherwise you'll have a memory leak.
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pointerPractice3() {
	cout << "================ pointerPractice3 ================" << endl;

	int a = 5;

	int* p = new int;
	*p = a;

	a++;
	cout << a << " " << *p << endl;

	// delete p; // This is the place to put it!
	p = &a; // Oops! Memory leak! Old address p was pointing to is now lost.

	a++;
	cout << a << " " << *p << endl;

	// If you uncomment this, your program will crash.
	// delete p; // Uh oh. Tried to use delete on memory that wasn't dynamically allocated!
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pointerPractice4() {
	cout << "================ pointerPractice4 ================" << endl;

	int x = 5;
	int* y = &x;

	int z = 42;

	// y = x;  // 1) Bad - value on left is int*, but on right is int. (Some compilers would allow this, but it's still almost always bad!)
	// &z = x; // 2) Bad - you can't change what the address of a variable is - can't have & on the left side
	// x = &z; // 3) Bad - value on left is int, but on right is int*. (Some compilers would allow this, but it's still almost always bad!)
	(*y)++;    // 4) Ok - changes the value that Y points to. Use parentheses so you don't have to think about order of operations.
	// y++; // 5) Eh.... this is "pointer arithmetic", in which you're moving the pointer to another spot in memory.
	        //    It's a bad idea for now, but it has some legitimate uses that we might see later.
			//    Bottom line: You "own" memory that you dynamically allocated, or that is used by variables you've declared.
			//                 Don't try to use memory you don't own.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void usingNULL() {
	cout << "================ usingNULL ================" << endl;
	int x = 5;
	int* p = &x;

	cout << x << " " << *p << endl;

	p = NULL; // p points at "nothing" now - actually memory address 0.
	          // So don't try to use p anymore.

	cout << p << endl;  // NULL is all 0's.
	// cout << *p << endl; // Error! Can't dereference NULL.
	// Similar idea to the "NullPointerException" in Java.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void passByValuePointers(int a, int* p1, int* p2, int* p3) {
	cout << "================ passByValuePointers =================" << endl;
	a = 95;

	p1 = new int;
	*p1 = 96;

	*p2 = 97;

	p3 = new int;
	*p3 = 98;
	// technically, we have a memory leak here, since we don't delete p1 or p3. This would have to be handled in the calling function...
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void passByReferencePointers(int a, int* p, int* &r) {
	cout << "================ passByReferencePointers =================" << endl;
	a = 95;

	p = new int;
	*p = 96;

	r = new int;
	*r = 97;

	// Technically, we're creating memory leaks here, but this would have to be handled in the calling function...
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	// Uncomment the example you want to run.

	// checkMemoryAddress();
	// pointers();
	dereferencing();

	// pointerPractice();
	// pointerPractice2();

	// dynamicMemoryAllocation();
	// pointerPractice3();

	// pointerPractice4();

	// usingNULL();

	// ---------------------------------
	// Supporting code for passByValuePointers
	/*
	int w = 2;
	int* x = &w;

	int* y = new int;
	*y = 3;

	int* z = new int;
	*z = 4;

	passByValuePointers(w, x, y, z);

	cout << w << ", " << *x << ", " << *y << ", " << *z << endl;
	delete y;
	delete z;
	*/

	// ---------------------------------
	// Supporting code for passByReferencePointers
	/*
	int i = 2;

	int* j = new int;
	*j = 3;

	int* k = new int;
	*k = 4;

	passByReferencePointers(i, j, k);

	cout << i << ", " << *j << ", " << *k << endl;
	delete j;
	delete k;
	*/

	// system("pause");

	return 0;
}
