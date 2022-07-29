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
	std::vector<Item> filteringSuppliers();
	std::vector<Item> filteringCategory();
	void displayProducts();
	void askAfterFiltering();
	void quickSortbyName(std::vector<Item>& arr, int l, int r);
	void quickSortbyPrice(std::vector<Item>& arr, int l, int r);
	Item getItem(int ID);
};