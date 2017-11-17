#pragma once

#include <iostream>
#include <string>

/*
Abstract base class for TransactionNode
*/
class Node
{
public:
	Node(const std::string &data = "");
	virtual ~Node() = 0;

	void setData(const std::string &data) { this->data = data; }
	void setLeft(Node* const& left) { this->left = left; }
	void setRight(Node* const& right) { this->right = right; }

	std::string getData() const { return data; }
	Node*& getLeft() { return left; }
	Node*& getRight() { return right; }

	virtual void printData() = 0;

protected:
	std::string data;
	Node *left, *right;

};
