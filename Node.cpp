#include "Node.h"

Node::Node(const std::string &data)
{
	this->data = data;
	left = right = nullptr;
}

Node::~Node()
{
	delete this->left;
	delete this->right;
}
