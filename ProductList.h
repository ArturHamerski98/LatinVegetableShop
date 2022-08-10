#pragma once
#include <vector>
#include "Item.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

class ProductList
{
public:
	std::list<Item> myList;
	void readingDataFromCSVFile();
	std::vector<Item> filteringSuppliers();
	std::vector<Item> filteringCategory();
	void displayProducts();
	void askAfterFiltering();
	void quickSortbyPriceAscending(std::vector<Item>& arr, int l, int r);
	void quickSortbyPriceDescending(std::vector<Item>& arr, int l, int r);
	void quickSortbyNameAscending(std::vector<Item>& arr, int l, int r);
	void quickSortbyNameDescending(std::vector<Item>& arr, int l, int r);
	Item getItem(int ID);
	
};