#pragma once
#include <vector>
#include "Item.h"
#include <fstream>
#include <string>
#include <sstream>

class ProductList
{
public:
	std::list<Item> myList;
	void readingDataFromCSVFile();
	std::vector<std::string> filteringSuppliers();
	std::vector<std::string> filteringCategory();
	void displayProducts();
	void askAfterFiltering();
};
