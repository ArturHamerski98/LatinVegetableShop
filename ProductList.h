#pragma once
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Item.h"

class ProductList
{
public:
	std::list<Item> myList;
	void readingDataFromCSVFile();
	void filteringSuppliers(std::string choosenSupplier);
	void filteringCategory(std::string choosenCategory);
	void displayProducts();
	int ranndomCategory(); 
	void sortingByName(int arr[], int l, int r);

};
