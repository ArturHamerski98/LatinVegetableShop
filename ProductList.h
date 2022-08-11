#pragma once
#include <vector>
#include "Item.h"
#include <fstream>
#include <string>
#include <sstream>
class ProductList
{
public:
	std::vector <Item*> vectorofAll;
	void readingDataFromCSVFile();
	std::vector<Item*> filteringSuppliers(std::vector<Item*>& arr);
	std::vector<Item*> filteringCategory(std::vector<Item*>& arr);
	void displayProducts(std::vector<Item*>& arr);
	void askAfterFiltering();
	void quickSortbyName(std::vector<Item*>& arr, int l, int r);
	void quickSortbyPrice(std::vector<Item*>& arr, int l, int r);
	void quickSortbyPriceAscending(std::vector<Item*>& arr, int l, int r);
	void quickSortbyPriceDescending(std::vector<Item*>& arr, int l, int r);
	void quickSortbyNameAscending(std::vector<Item*>& arr, int l, int r);
	void quickSortbyNameDescending(std::vector<Item*>& arr, int l, int r);
	Item getItem(int ID);
	static std::string proText(std::string a, int margin);
	void addNewProduct();
};