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
	std::vector<Item> filteringSuppliers(std::string choosenSupplier);
	std::vector<std::string> filteringCategory(std::string choosenCategory);
	void displayProducts();
	void quickSort(std::vector<double>& arr, double l, double r);
};
