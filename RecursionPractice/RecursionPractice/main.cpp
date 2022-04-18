//////////////////////////////////////////////////////////////////////
// Steven Bogaerts
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "IntNode.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Root Beer

// Infinite recursion! (There's no base case.)
/*
void annoyingSongInf(int numBottles) {
	cout << numBottles << " bottles of beer on the wall." << endl;
	cout << numBottles << " bottles of beer!" << endl; 
	cout << "Take one down. Pass it around." << endl;
	cout << "There'll be " << numBottles-1 
		 << " bottles of beer on the wall." << endl << endl;

	annoyingSongInf(numBottles-1);
}
*/

void annoyingSong(int numBottles) {
	if (numBottles == 0)
		cout << "That's all folks!" << endl;   // base case
	else {
		cout << numBottles << " bottles of beer on the wall." << endl;
		cout << numBottles << " bottles of beer!" << endl; 
		cout << "Take one down. Pass it around." << endl;
		cout << "There'll be " << numBottles-1 
			 << " bottles of beer on the wall." << endl << endl;

		annoyingSong(numBottles-1);
	}
}

//////////////////////////////////////////////////////////////////////
// Factorial

int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n-1);
}

//////////////////////////////////////////////////////////////////////
// Review of Function Calls

int c(int x) {
	return x + 4;
}

int b(int x) {
	if (x < 5)
		return c(x * 2) + 1;
	else
		return c(x) + 1;
}

int a(int x) {
	int ans = b(x + 1);
	if (ans % 2 == 0)
		return ans + 1;
	else
		return ans - 1;
}

//////////////////////////////////////////////////////////////////////
// The Fibonacci Sequence

// The Fibonacci numbers are 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
// So for example, 3 is the 4th Fibonacci number (for n == 4).

// n must be an integer >= 1.
int fibonacci(int n) {
	if ((n == 1) || (n == 2))
		return 1;
	else
		return fibonacci(n-1) + fibonacci(n-2);
}

//////////////////////////////////////////////////////////////////////
// Exponentials

// returns a to the nth power
int recPowerv1(int a, int n) {
	if (n == 0)
		return 1;
	else {
		cout << "*";
		return a * recPowerv1(a, n-1);
	}
}

int iterPowerv1(int a, int n) {
	int prod = 1;
	for (int i = 0; i < n; i++) {
		// cout << "*";
		prod = prod * a;
	}
	return prod;
}

// returns a to the nth power
int recPowerv2(int a, int n) {
	if (n == 0)
		return 1;
	else {
		int anOver2 = recPowerv2(a, n/2); // compute a^(n/2), where n/2 is integer division, not "mathematical" division
		if (n % 2 == 0) {
			cout << "*";
			return anOver2 * anOver2;
		}
		else {
			cout << "**"; // Two *, because two multiplcations in the line below
			return a * anOver2 * anOver2;
		}
	}
}

// Just for fun - you don't have to worry about how this works unless you want to.
int iterPowerv2(int a, int n) {
	int extra = 1;
	while (n != 1) {
		if (n%2 != 0) {
			// cout << "*";
			extra = extra * a;
		}
		// cout << "*";
		a = a * a;
		n = n / 2;
	}
	return a * extra;
}

//////////////////////////////////////////////////////////////////////
// Summing a Linked List

int sumLLRecursive(IntNode* head) {
	if (head == NULL)
		return 0;
	else {
		int sumOfRest = sumLLRecursive(head->next);
		return head->data + sumOfRest;
		//return head->data + sumLLRecursive(head->next);
	}
}

int sumLLIterative(IntNode* head) {
	int sum = 0;
	IntNode* curr = head;

	while(curr != NULL) {
		sum += curr->data;
		curr = curr->next;
	}

	return sum;
}

int sumLLWRONG(IntNode* head) {
	int sum = 0;

	if (head == NULL)
		return 0;
	else {
		sum += head->data;
		sumLLWRONG(head->next);
		return sum;
	}
}

//////////////////////////////////////////////////////////////////////
// Summing an Array

int sumArrayWRONG(int nums[], int length) {
	int currIndex = -1;
	if (currIndex == length)
		return 0;
	else {
		currIndex++;
		return nums[currIndex] + sumArrayWRONG(nums, length);
	}
}

int sumArrayRecursiveHelper(int nums[], int length, int currIndex) {
	if (currIndex == length)
		return 0;
	else
		return nums[currIndex] + sumArrayRecursiveHelper(nums, length, currIndex+1);
}

int sumArrayRecursive(int nums[], int length) {
	return sumArrayRecursiveHelper(nums, length, 0);	
}

int sumArrayIterative(int nums[], int length) {
	int sum = 0;
	for(int i = 0; i < length; i++)
		sum += nums[i];
	return sum;
}

//////////////////////////////////////////////////////////////////////
// Towers of Hanoi

// Move n disks from source to dest using temp.
// Move n disks from 1 position to 2nd position using 3rd position
void printHanoiSolutionHelper(int n, string source, string dest, string temp) {
	if (n == 1)
		cout << "Move disk from " << source << " to " << dest << "." << endl;
	else {
		printHanoiSolutionHelper(n-1, source, temp, dest  );
		printHanoiSolutionHelper(1  , source, dest, temp  );
		printHanoiSolutionHelper(n-1, temp  , dest, source);
	}
}

void printHanoiSolution(int n) {
	printHanoiSolutionHelper(n, "A", "C", "B");
}

//////////////////////////////////////////////////////////////////////

void remove(IntNode* &head, int toRemove) {
	if (head != NULL) {
		if (head->data == toRemove) {
			IntNode* temp = head;

			head = head->next;
			delete temp;
			temp = NULL;
		}
		else {
			remove(head->next, toRemove);
		}
	}
}

void print(IntNode* head) {
	IntNode* curr = head;
    while (curr != NULL) {
      cout << curr->data << endl;
      curr = curr->next;
    }	
}

//////////////////////////////////////////////////////////////////////////
int addOddsInList(IntNode* head) {
	if (head == NULL)
		return 0;
	else {
		/*
		if (head->data % 2 == 0)
			return addOddsInList(head->next);
		else
			return head->data + addOddsInList(head->next);
		*/

		int sumOfOddsInRestOfList = addOddsInList(head->next);
		if (head->data % 2 == 0)
			return sumOfOddsInRestOfList;
		else
			return head->data + sumOfOddsInRestOfList;
	}
}

int addOddsInList2Helper(IntNode* head, int sumSoFar) {
	if (head == NULL)
		return sumSoFar;
	else {
		if (head->data % 2 == 0)
			return addOddsInList2Helper(head->next, sumSoFar);
		else
			return addOddsInList2Helper(head->next, head->data + sumSoFar);
	}
}

int addOddsInList2(IntNode* head) {
	return addOddsInList2Helper(head, 0);
}

// Given an array nums of the given length, adds all the odd numbers 
// starting at currIndex, to the end of the array.
int addOddsInArrayHelper(int nums[], int length, int currIndex) {
	if (currIndex == length)
		return 0;
	else {
		int sumOfOddsInRestOfArray = addOddsInArrayHelper(nums, length, currIndex + 1);
		if (nums[currIndex] % 2 == 0)
			return sumOfOddsInRestOfArray;
		else
			return nums[currIndex] + sumOfOddsInRestOfArray;
	}
}

int addOddsInArray(int nums[], int length) {
	return addOddsInArrayHelper(nums, length, 0);
}

//////////////////////////////////////////////////////////////////////////
// Average of the values in a linked list

int lengthLL(IntNode* head) {
	if (head == NULL)
		return 0;
	else
		return 1 + lengthLL(head->next);
}

// 999, 6, 8
// return lengthLL(head) + lengthLL(head->next);    --> 3 + 2 --> 5

// 999, 6, 8
// return head->data + lengthLL(head->next);    --> 999 + 2 --> 1001

double averageInLL(IntNode* head) {
	return sumLLRecursive(head) / lengthLL(head);
}

// Assume at least one element in the list
double averageInLL2Helper(IntNode* head, int sumSoFar, int lengthSoFar) {
	if (head->next == NULL) {
		sumSoFar += head->data;
		lengthSoFar++;
		return sumSoFar / lengthSoFar;
	}
	else {
		return averageInLL2Helper(head->next, sumSoFar + head->data, lengthSoFar + 1);
	}
}

double averageInLL2(IntNode* head) {
	return averageInLL2Helper(head, 0, 0);
}

//////////////////////////////////////////////////////////////////////////
// Sequence of numbers 
// The sequence of numbers 2, 3, 5, 14, 69, 965, 66584, ... starts with 2 and 3, with each subsequent number being the product of the previous 2, minus 1. For example, 2*3-1=5,   3*5-1 = 14,    5*14-1 = 69, etc. For a given value i, return the ith number in this sequence.

// seq(i) returns the ith number in the sequence.
int seq(int i) {
	if (i == 1)
		return 2;
	else if (i == 2)
		return 3;
	else
		return seq(i - 1) * seq(i - 2) - 1;
}


//////////////////////////////////////////////////////////////////////////
// What's wrong with the following code?

int sumArrayWRONG2Helper(int nums[], int length, int currIndex) {
	if (currIndex == length)
		return 0;
	else
		return nums[currIndex] + sumArrayWRONG2Helper(nums, length, currIndex++);
}

int sumArrayWRONG2(int nums[], int length) {
	return sumArrayWRONG2Helper(nums, length, 0);
}

//////////////////////////////////////////////////////////////////////////
int main() {
	// Uncomment one or more of the following to see the results

	/////////////////////// Root beer ////////////////////////////////////////////////////
	// annoyingSongInf(20); // infinite loop!
	annoyingSong(20);

	/////////////////////// Factorial ////////////////////////////////////////////////////
	
	cout << factorial(4) << endl;
	cout << factorial(7) << endl;

	/////////////////////// Function calls practice////////////////////////////////////////////////////
	// cout << a(3) << endl;

	/////////////////////// Fibonacci sequence ////////////////////////////////////////////////////
	/*
	// The Fibonacci numbers are 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
	// So for example, 3 is the 4th Fibonacci number (for n == 4).
	cout << fibonacci(3) << endl;
	cout << fibonacci(6) << endl;
	*/

	/////////////////////// a to the nth power ////////////////////////////////////////////////////
	/*
	cout << recPowerv1(3, 3) << " : " << 3 * 3 * 3 << endl;
	cout << recPowerv2(3, 3) << " : " << 3 * 3 * 3 << endl;
	cout << "----------------------" << endl;
	cout << recPowerv1(2, 17) << " : " << 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 << endl;
	cout << recPowerv2(2, 17) << " : " << 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 << endl;
	cout << "----------------------" << endl;
	// If you try to go too high, you'll get 0 due to the limitations of ints. Could change to long though...
	cout << recPowerv1(2, 30) << endl;
	cout << recPowerv2(2, 30) << endl;
	*/

	/*
	cout << iterPowerv1(2, 17) << endl;
	cout << iterPowerv2(2, 17) << endl;
	cout << "----------------------" << endl;
	cout << iterPowerv1(2, 30) << endl;
	cout << iterPowerv2(2, 30) << endl;
	*/

	/////////////////////// Summing a linked list ////////////////////////////////////////////////////
	/*
	IntNode* head = new IntNode;
	head->data = 3;

	IntNode* b = new IntNode;
	b->data = 5;

	IntNode* c = new IntNode;
	c->data = 10;

	head->next = b;
	b->next = c;
	c->next = NULL;

	//cout << sumLLRecursive(head) << " : " << sumLLIterative(head) << ", wrong: " << sumLLWRONG(head) << endl;
	//remove(head, 5);
	//print(head);

	// cout << addOddsInList(head) << ", " << addOddsInList2(head) << endl;

	// cout << averageInLL(head) << ", " << averageInLL2(head) << endl;

	/////////////////////// Summing an array ////////////////////////////////////////////////////
	
	int nums[] = {4,2,3,5,7,6,4,7,8,9,6,4,2,1,2,3,7,4}; // length 18
	// cout << sumArrayRecursive(nums, 18) << " : " << sumArrayIterative(nums, 18) << endl;
	// cout << sumArrayWRONG2(nums, 18) << endl;
	
	int x = 5;
	cout << "Before: " << x << endl;
	cout << "Returned: " << x++ << endl;
	cout << "After: " << x << endl;

	/////////////////////// Towers of Hanoi ////////////////////////////////////////////////////
	printHanoiSolution(3);
	cout << "---------------------" << endl;
	printHanoiSolution(7);
	cout << "---------------------" << endl;
	printHanoiSolution(20); // Lots of output
	*/

	return 0;
}
