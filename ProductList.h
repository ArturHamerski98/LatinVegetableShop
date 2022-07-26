#pragma once
#include <list>
#include <vector>
#include "Item.h"
class ProductList
{
public:
	std::list<Item> myList;
	std::vector<Item> sortingByPrice(std::list<Item> myList2);
	void readingDataFromCSVFile();
};
