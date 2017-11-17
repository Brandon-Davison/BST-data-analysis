#include "BST.h"

BST::BST()
{
	root = nullptr;
}

BST::~BST()
{
	destroyTree(root);
}

void BST::setRoot(Node* const& root)
{
	this->root = root;
}

Node* BST::getRoot() const
{
	return root;
}

void BST::insert(TransactionNode*& newNode) 
{
	insert(root, newNode);
}

void BST::inOrderTraversal() const
{
	inOrderTraversal(root);
	std::cout << std::endl;
}

TransactionNode* BST::findSmallest() const
{
	TransactionNode *node = dynamic_cast<TransactionNode*>(this->root);

	while (node != nullptr && node->getLeft() != nullptr)
	{
		node = dynamic_cast<TransactionNode*>(node->getLeft());
	}
	return node;
}

TransactionNode* BST::findLargest() const 
{
	TransactionNode *node = dynamic_cast<TransactionNode*>(this->root);

	while (node != nullptr && node->getRight() != nullptr)
	{
		node = dynamic_cast<TransactionNode*>(node->getRight());
	}
	return node;
}

void BST::destroyTree(Node *root) 
{
	if (root != nullptr)
	{
		destroyTree(root->getLeft());
		destroyTree(root->getRight());
		delete root;
	}
}

void BST::insert(Node*& parent, TransactionNode*& newNode) 
{
	if (parent == nullptr && newNode != nullptr)
	{
		parent = newNode;
	}
	else if (newNode->getUnits() != (dynamic_cast<TransactionNode*>(parent))->getUnits()) // check for duplicate.
	{
		if (newNode->getUnits() > (dynamic_cast<TransactionNode*>(parent))->getUnits()) // go to right subtree
		{
			insert(parent->getRight(), newNode);
		}
		else
		{
			insert(parent->getLeft(), newNode); // go to left subtree
		}
	}
}

void BST::inOrderTraversal(Node *root) const
{
	if (root != nullptr)
	{
		this->inOrderTraversal(root->getLeft());
		root->printData();
		this->inOrderTraversal(root->getRight());
	}
}
