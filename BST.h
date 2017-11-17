#pragma once

#include <iostream>

#include "Node.h"
#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();

	void setRoot(Node* const& root);
	Node* getRoot() const;

	// calls corresponding private member functions. 
	void insert(TransactionNode*& newNode);
	void inOrderTraversal() const;

	TransactionNode* findSmallest() const;
	TransactionNode* findLargest() const;

private:
	Node* root; 

	void destroyTree(Node *root);

	void insert(Node*& parent, TransactionNode*& newNode);
	void inOrderTraversal(Node *root) const;
};
