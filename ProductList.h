#pragma once


#include <list>
#include <vector>
#include <algorithm>
#include "Item.h"

class ProductList
{
public:
	std::vector<int> sortingByPrice(std::list<Item> myList2);
	//std::vector<Item> sortingByName(std::list<Item> myList2);
	std::vector<std::string> filteringSuppliers(std::list<Item> myList2);
	//std::vector<std::string> filteringCategory(std::list<Item> myList2);
	void displayProducts(std::list<Item>myList2);

};
