/////////////////////////////////////////////////////////////////////////
// Steven Bogaerts
/////////////////////////////////////////////////////////////////////////

#include "IntNode.h"
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////
void print(IntNode* head) {
	IntNode* curr = head;
    while (curr != NULL) {
      cout << curr->data << endl;
      curr = curr->next;
    }	
}

/////////////////////////////////////////////////////////////////////////
int length(IntNode* head) {
	cout << "-------------------- length --------------------" << endl;
	IntNode* curr = head;
	int count = 0;
	while (curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

/////////////////////////////////////////////////////////////////////////
int sum(IntNode* head) {
	cout << "-------------------- sum --------------------" << endl;
	IntNode* curr = head;
	int sum = 0;
	while (curr != NULL) {
		sum += curr->data;
	    curr = curr->next;
	}
	return sum;
}

/////////////////////////////////////////////////////////////////////////
bool member1(IntNode* head, int n) {
	cout << "-------------------- member1 --------------------" << endl;
	IntNode* curr = head;

	while (curr != NULL) {
		if (curr->data == n)
			return true;
		// else // WRONG!
		//	return false; // WRONG!
		curr = curr->next;
	}
	// If you get here, n isn't in the list.
	return false;
}

/////////////////////////////////////////////////////////////////////////
// This way isn't as good! Why not?
bool member2(IntNode* head, int n) {
	cout << "-------------------- member2 --------------------" << endl;
	IntNode* curr = head;
	bool foundIt = false;

	while (curr != NULL) {
		if (curr->data == n)
			foundIt = true;
		curr = curr->next;
	}

	return foundIt;
}

/////////////////////////////////////////////////////////////////////////
void insertAfter(IntNode* before, int newData) {
	cout << "-------------------- insertAfter --------------------" << endl;

	IntNode* after = new IntNode;

	after->data = newData;

	after->next = before->next;
	before->next = after;  // (*before).next = after;
}

/////////////////////////////////////////////////////////////////////////
void insertAfterWRONG(IntNode* before, int newData) {
	cout << "-------------------- insertAfterWRONG --------------------" << endl;

	// Draw a picture to demonstrate what goes wrong with this code.

	IntNode* after = new IntNode;

	after->data = newData;

	// The only difference is that these two lines are switched:
	before->next = after;
	after->next = before->next;
}

////////////////////////////////////////////////////////////////////////
// Big picture: we need to use pointers to nodes, not the objects themselves, 
// nor references (for the most part), otherwise there'll be trouble.

// What kind of trouble? The answer is not a required part of this course, 
// but read the rest of this section if you're curious...

// BEGIN OPTIONAL MATERIAL
// Using objects, instead of pointers.
void insertAfterWRONG2(IntNode before, int newData) {
	cout << "-------------------- insertAfterWRONG2 --------------------" << endl;
	// Pass by value makes a copy! So before is a copy! We're changing the copy's next, not the original's next!

	IntNode after;

	after.data = newData;
	
	after.next = before.next;
	before.next = &after;
}

// Pass by reference instead of by value, still use an object inside the function.
void insertAfterWRONG3(IntNode &before, int newData) {
	cout << "-------------------- insertAfterWRONG3 --------------------" << endl;

	IntNode after;

	after.data = newData;
	
	after.next = before.next;
	before.next = &after; // Bad - after is a local variable, so its memory will no longer be reserved when the method ends.
	                      // This could lead to unpredictable behavior / crash.
}

// Pass by reference, but use a pointer with dynamically allocated memory for "after" inside the function, so it doesn't 
// fall out of scope.
// This actually works, but you might as well just use pointers everywhere rather than try to figure out
// where references are ok and where they aren't.
void insertAfter4(IntNode &before, int newData) {
	cout << "-------------------- insertAfter4 --------------------" << endl;

	IntNode* after = new IntNode;

	after->data = newData;
	
	after->next = before.next;
	before.next = after;
}

// END OPTIONAL MATERIAL

/////////////////////////////////////////////////////////////////////////
// Rather than trying to draw a reference to a pointer, think of it like this:
// Pass by reference enables changes to the argument to be seen by the caller of the method.

// For example, if you have a parameter   int &x
// Then you can say            x = something;
// inside of the method, and the change you make will be seen by the caller of the method.

// Similarly, if you have a parameter     IntNode* &head

// Same thing here - passing the head pointer by reference means that we can make it point
// somewhere else and the caller will see that change.

// That is, because we say    head =    in this code, we need to pass by reference
void insertFront(IntNode* &head, int n) {
	cout << "-------------------- insertFront --------------------" << endl;
	IntNode* newFront = new IntNode;
	newFront->data = n;
	newFront->next = head;
	head = newFront;
}

/////////////////////////////////////////////////////////////////////////
void insertBack(IntNode* &head, int n) {
	cout << "-------------------- insertBack --------------------" << endl;

	IntNode* back = new IntNode;
	back->data = n;
	back->next = NULL;

	if (head == NULL)
		head = back;
	else {
		IntNode* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		// Now, curr is pointing at the last node in the list

		curr->next = back;
	}
}

/////////////////////////////////////////////////////////////////////////
void removeFirst(IntNode* &head) {
	cout << "-------------------- removeFirst --------------------" << endl;

	if (head != NULL) {
		IntNode* temp = head;

		head = head->next;
		delete temp;
		temp = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////
bool remove(IntNode* &head, int n) { // n is a value
	cout << "-------------------- remove --------------------" << endl;

	IntNode* curr = head;
	IntNode* prev = NULL;

	//     we haven't reached the end   AND   we haven't found n
	while ((curr != NULL) && (curr->data != n)) {
		prev = curr;
		curr = curr->next;
	}
	// If we found n, then curr is pointing to the node with n, 
	// and prev is pointing to the node before.
	// Otherwise curr is NULL - we went through the entire list, and never found n.

	if ((prev == NULL) && (curr != NULL)) { // n is at the head
		head = head->next;
		delete curr;
		curr = NULL;
		return true;
	}
	else if (curr != NULL) { // n is after the head somewhere
		prev->next = curr->next;
		delete curr;
		curr = NULL;
		return true;
	}
	else // curr==NULL, so didn't find it
		return false;
}

/////////////////////////////////////////////////////////////////////////
int get(IntNode* head, int index) {
	cout << "-------------------- get --------------------" << endl;
	int currIndex = 0;
	IntNode* currNode = head;

	while ((currNode != NULL) && (currIndex < index)) {
		currNode = currNode->next;
		currIndex++;
	}

	if ((currNode != NULL) && (currIndex == index))
		return currNode->data;
	else
		return -1; // Or signal an error, or ???
}


/////////////////////////////////////////////////////////////////////////
void deleteEntireList(IntNode* &head) {
	cout << "-------------------- deleteEntireList --------------------" << endl;

	IntNode* curr = head;
	IntNode* toDelete;

	while (curr != NULL) {
		toDelete = curr;
		curr = curr->next;
		delete toDelete;
		toDelete = NULL;

		// NO:
		// delete curr;
		// curr = curr->next; // dereferencing deleted memory!
	}

    head = NULL;
}

/////////////////////////////////////////////////////////////////////////

/*
int main() {
	IntNode* h = new IntNode;
	h->data = 5;

	IntNode* b = new IntNode;
	h->data = 2;

	IntNode* c = new IntNode;
	h->data = 6;

	h->next = b;
	b->next = c;
	c->next = NULL;

	/*
	IntNode* curr = h;
	int i = 0;
	while (curr != NULL) {
		cout << i << ":" << endl;
		print(curr);
		curr = curr->next;
		i++;
	}
	*/
/*
	cout << "Call on h:" << endl;
	print(h);

	cout << "Call on b:" << endl;
	print(b);

	return 0;
}
*/

int main() {
	// Put the data in the nodes
	IntNode* head = new IntNode;
	head->data = 3;

	IntNode* b = new IntNode;
	b->data = 4;

	IntNode* c = new IntNode;
	c->data = 6;

	IntNode* d = new IntNode;
	d->data = 13;

	// Link everything up
	head->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL; // What happens if you don't do this? Why?

	// Choose one or more functions to call:
	print(head);

	remove(head, 6);
	cout << "Removing 6, then afterwards:" << endl;
	print(head);

	/*
	cout << length(head) << endl;

	cout << sum(head) << endl;

	cout << member1(head, 6) << endl;
	cout << member1(head, 7) << endl;

	cout << member2(head, 6) << endl;
	cout << member2(head, 7) << endl;

	insertAfter(head, 91);
	print(head);

	insertAfter(d, 92);
	print(head);

	insertAfter(head->next->next, 93);
	print(head);
	*/

	///////////////////////////////////////////////////
	// Optional stuff

	// This would introduce an infinite loop!
	// insertAfterWRONG(head, -1);
	// print(head);

	// This has no effect!
	// insertAfterWRONG2(*head, -2);
	// print(head);

	// This would make the program crash!
	// insertAfterWRONG3(*head, -3);
	// print(head);

	// This actually works, but just use pointers instead, for consistency.
	// insertAfter4(*head, -4);
	// print(head);
	///////////////////////////////////////////////////

	insertFront(head, 999);
	print(head);

	/*
	insertBack(head, 8888);
	print(head);

	remove(head, 6);
	print(head);

	remove(head, 999);
	print(head);

	removeFirst(head);
	print(head);
	*/

	cout << "Element at index 0: " << get(head, 3) << endl;
	cout << "Element at index 3: " << get(head, 3) << endl;
	cout << "Element at index 4: " << get(head, 4) << endl;
	cout << "Starting at head->next, element at index 3: " << get(head->next, 3) << endl;
	cout << "Given bad index: " << get(head, -4) << endl;
	cout << "Given bad index: " << get(head, 6) << endl;
	cout << "Head is NULL: " << get(NULL, 0) << endl;

	cout << "Before deleting, head address is: " << head << endl;
	cout << "Before deleting, head data is:" << head->data << endl;
	deleteEntireList(head);
	cout << "After deleting, head address is: " << head << endl;
	// cout << "After deleting, head data is:" << head->data << endl;

	return 0;
}

void anotherCreationExample() {
	// Put the data in the nodes
	IntNode* head = new IntNode;
	head->data = 3;

	head->next = new IntNode;
	IntNode* curr = head->next;
	curr->data = 4;
	curr->next = NULL;
}
