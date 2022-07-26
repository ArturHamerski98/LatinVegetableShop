#pragma once
#include <list>
#include <vector>
#include "Item.h"

class ProductList
{
public:
	std::list<Item> myList;
	void readingDataFromCSVFile();
};