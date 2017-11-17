#include "TransactionNode.h"

TransactionNode::TransactionNode(const std::string &data, const int &units) : Node(data)
{
	this->units = units;
}

TransactionNode::~TransactionNode()
{
	delete this->left;
	delete this->right;
}

void TransactionNode::setUnits(const int &units)
{
	this->units = units;
}

int TransactionNode::getUnits() const
{
	return units;
}

void TransactionNode::printData()
{
	std::cout << units << " units of " << data << std::endl;
}

bool TransactionNode::operator>(TransactionNode &node) { return false; }
