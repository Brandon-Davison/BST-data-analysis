#pragma once

#include <iostream>
#include <string>

#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(const std::string &data = "", const int &units = 0);
	~TransactionNode();

	void setUnits(const int &units);
	int getUnits() const;

	void printData();

	bool operator>(TransactionNode &node);

private:
	int units;

};