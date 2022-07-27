#pragma once
#include <list>
#include <vector>
#include "Item.h"

class ProductList
{
public:
	std::list<Item> myList;
	void readingDataFromCSVFile();
	void filteringSuppliers(std::string choosenSupplier);
	void displayProducts();
	void filteringCategory(std::string choosenCategory);
};
