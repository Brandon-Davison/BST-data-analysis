#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

#include "BST.h"
#include "TransactionNode.h"

class DataAnalysis
{
public:
	DataAnalysis();

	void runAnalysis();

	void displayTrends();

private:
	BST *treeSold, *treePurchased;
	std::ifstream csvStream;

	void readLine(int *units, std::string *type, std::string *transaction);
	void readFileIntoTree();

};
