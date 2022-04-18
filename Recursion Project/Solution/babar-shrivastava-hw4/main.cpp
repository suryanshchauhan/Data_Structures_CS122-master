#include <iostream>
#include <string>
#include "IntNode.h"

using namespace std;

int product(int m, int n)
{
	if (m == n)
	{
		return n;
	}
	else if (m < n)
	{
		return m * product(m + 1, n);
	}
	else if (m > n)
	{
		return m * product(m - 1, n);
	}
}

int findMaxInList(IntNode* head)
{
	int max = head->data;
	if (head->next == NULL)
	{
		return max;
	}
	else
	{
		if (max > findMaxInList(head->next))
		{
			return max;
		}
		else
		{
			return findMaxInList(head->next);
		}
	}
}

int sumEvens(IntNode* head)
{
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		if (head->data % 2 == 0)
		{
			return head->data + sumEvens(head->next);
		}
		else
		{
			return sumEvens(head->next);
		}
	}
}

int main()
{
	cout << "////////////////////////////////// product /////////////////////////////////////" << endl;
	cout << product(0, 2) << endl;
	cout << product(2, 3) << endl;
	cout << product(3, 3) << endl;
	cout << product(4, 2) << endl;

	cout << "////////////////////////////////// findMaxInList ///////////////////////////////" << endl;
	IntNode* head = new IntNode;
	head->data = 3;

	IntNode* b = new IntNode;
	b->data = 5;

	IntNode* c = new IntNode;
	c->data = 10;

	IntNode* d = new IntNode;
	d->data = 20;

	head->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;

	cout << findMaxInList(head) << endl;

	cout << "////////////////////////////////// sumEvens ////////////////////////////////////" << endl;
	cout << sumEvens(head) << endl;

	return 0;
}