#include <iostream>
#include "tree.h"

using namespace std;


void preorderPrint(IntBTNode* root) {
	if (root != NULL) {
		cout << root->data << endl;
		preorderPrint(root->left);
		preorderPrint(root->right);
	}
}


/////////////////////////////////////////////////////////////////////////////
void inorderPrint(IntBTNode* root) {
	if (root != NULL) {
		inorderPrint(root->left);
		cout << root->data << endl;
		inorderPrint(root->right);
	}
}

/////////////////////////////////////////////////////////////////////////////
// Sum

int sumTree(IntBTNode* root) {
	if (root == NULL)
		return 0;
	else {
		int sumLeftSubtree = sumTree(root->left);
		int sumRightSubtree = sumTree(root->right);
		return root->data + sumLeftSubtree + sumRightSubtree;
		// return root->data + sumTree(root->left) + sumTree(root->right);
	}
}

/////////////////////////////////////////////////////////////////////////////
// find

IntBTNode* findIter(IntBTNode* root, int value) {
	IntBTNode* temp = root;

	while (temp != NULL) {
	    if ( value < temp->data )
			temp = temp->left;
		else if ( value > temp->data )
			temp = temp->right;
		else // we found it!
			return temp;
	}

	return NULL;	
}

IntBTNode* findRec(IntBTNode* root, int value) {
	if (root == NULL)
		return NULL;
	else if (root->data == value)
		return root;
	else if (root->data > value)
		return findRec(root->left, value);
	else
		return findRec(root->right, value);
}

/////////////////////////////////////////////////////////////////////////////
// insert

void insertIter(IntBTNode* &root, int value) {
	// Create node with the new value in it.
	IntBTNode* add = new IntBTNode;
	add->data = value;
	add->left = NULL;
	add->right = NULL;

	// If tree is empty, new node is the root, then
	// exit the method.
	if (root == NULL)
		root = add;
	else {
		IntBTNode* curr = root;
		IntBTNode* prev;
		while (curr != NULL) {
			prev = curr;
			if (value < prev->data)
				curr = curr->left;
			else
				curr = curr->right;
		}

		// Now, curr is NULL, but prev is the parent of where the new node should go.
		if (value < prev->data)
			prev->left = add;
		else
			prev->right = add;
	}
}

void insertRecHelper(IntBTNode* &root, IntBTNode* add) {
	if (root == NULL)
		root = add;
	else {
		if (add->data < root->data)
			insertRecHelper(root->left, add);
		else
			insertRecHelper(root->right, add);
	}
}

void insertRec(IntBTNode* &root, int value) {
	IntBTNode* add = new IntBTNode;
	add->data = value;
	add->left = NULL;
	add->right = NULL;

	insertRecHelper(root, add);
}

/////////////////////////////////////////////////////////////////////////////
// Does a postorder traversal to delete the entire tree.
void deleteAll(IntBTNode* root) {
	if (root != NULL) {
		deleteAll(root->left);
		deleteAll(root->right);
		delete root;
		root = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////
// Returns the root of the newly-built tree, of this form:
//           27
//     13           42
//  6     21      39   61
IntBTNode* buildAParticularTree() {
	IntBTNode* rootNode = new IntBTNode;
	rootNode->data = 27;

	IntBTNode* leftNode = new IntBTNode;
	leftNode->data = 13;

	IntBTNode* rightNode = new IntBTNode;
	rightNode->data = 42;

	IntBTNode* leftLeftNode = new IntBTNode;
	leftLeftNode->data = 6;

	IntBTNode* leftRightNode = new IntBTNode;
	leftRightNode->data = 21;

	IntBTNode* rightLeftNode = new IntBTNode;
	rightLeftNode->data = 39;

	IntBTNode* rightRightNode = new IntBTNode;
	rightRightNode->data = 61;

	rootNode->left = leftNode;
	rootNode->right = rightNode;

	leftNode->left = leftLeftNode;
	leftNode->right = leftRightNode;

	rightNode->left = rightLeftNode;
	rightNode->right = rightRightNode;

	leftLeftNode->left = NULL;
	leftLeftNode->right = NULL;

	leftRightNode->left = NULL;
	leftRightNode->right = NULL;

	rightLeftNode->left = NULL;
	rightLeftNode->right = NULL;

	rightRightNode->left = NULL;
	rightRightNode->right = NULL;

	return rootNode;
}


/////////////////////////////////////////////////////////////////////////////
int main() {
	IntBTNode* root = buildAParticularTree();

	////////////////////////////////////////////////////
	cout << "============== sumTree ===============" << endl;
	int sum = sumTree(root);
	cout << sum << endl; // Should be 209

	////////////////////////////////////////////////////
	cout << "============== find ===============" << endl;
	IntBTNode* find39 = findIter(root, 39);
	IntBTNode* find40 = findIter(root, 40);

	cout << find39 << ", " << find39->data << endl;
	cout << find40 << endl;

	find39 = findRec(root, 39);
	find40 = findRec(root, 40);

	cout << find39 << ", " << find39->data << endl;
	cout << find40 << endl;

	////////////////////////////////////////////////////
	cout << "============== insert ===============" << endl;

	cout << "----- insert 40 -----" << endl;
	insertIter(root, 40);
	inorderPrint(root);

	cout << "----- insert 41 -----" << endl;
	insertIter(root, 41);
	inorderPrint(root);

	cout << "----- insert 50 -----" << endl;
	insertIter(root, 50);
	inorderPrint(root);

	// reset the tree, then try the recursive version
	cout << "----- reset -----" << endl;
	deleteAll(root);
	root = buildAParticularTree();

	cout << "----- insert 40 -----" << endl;
	insertRec(root, 40);
	inorderPrint(root);

	cout << "----- insert 41 -----" << endl;
	insertRec(root, 41);
	inorderPrint(root);

	cout << "----- insert 50 -----" << endl;
	insertRec(root, 50);
	inorderPrint(root);

	////////////////////////////////////////////////////
	deleteAll(root);

	return 0;
}
