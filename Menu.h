#pragma once
#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "Userek.h"

class Menu {
public:
	std::string log;
	ProductList productList;
	Cart cart;
	Userek user;
public:
	void superMenu();
	void askAfterFiltering(std::vector<Item*>);
	Menu();
};