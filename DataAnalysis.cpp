#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
	treeSold = new BST();
	treePurchased = new BST();

	// open file and clear first line "Units,Type,Transaction"
	std::string str;
	csvStream.open("data.csv");
	std::getline(csvStream, str); 
}

void DataAnalysis::runAnalysis()
{
	readFileIntoTree();

	treePurchased->inOrderTraversal();
	std::cout << std::endl;
	treeSold->inOrderTraversal();

	displayTrends();
}

void DataAnalysis::displayTrends()
{	
	std::cout << "Least purchased: ";
	(dynamic_cast<TransactionNode*>(treePurchased->findSmallest())->printData());

	std::cout << "Least sold: ";
	(dynamic_cast<TransactionNode*>(treeSold->findSmallest())->printData());

	std::cout << std::endl;

	std::cout << "Most purchased: ";
	(dynamic_cast<TransactionNode*>(treePurchased->findLargest())->printData());

	std::cout << "Most sold: ";
	(dynamic_cast<TransactionNode*>(treeSold->findLargest())->printData());

}

void DataAnalysis::readLine(int *units, std::string *type, std::string *transaction)
{
	std::string line, token;
	std::getline(csvStream, line);
	std::istringstream ss(line);

	try
	{
		std::getline(ss, token, ',');
		*units = std::stoi(token);

		std::getline(ss, token, ',');
		*type = token;

		std::getline(ss, token, ',');
		*transaction = token;
	}
	catch (...) {} // reached end of file.
}

void DataAnalysis::readFileIntoTree()
{
	int units;
	std::string type, transaction;

	while (csvStream.good())
	{
		readLine(&units, &type, &transaction); 
		TransactionNode *node = new TransactionNode(type, units); 
		transaction == "Purchased" ? treePurchased->insert(node) : treeSold->insert(node);
	}
}
