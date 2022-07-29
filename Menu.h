#pragma once
#include "Item.h"
#include "ProductList.h"
#include "Cart.h"

class Menu {
public:
	ProductList productList;
	Cart cart;
public:
	void superMenu();
	void askAfterFiltering(std::vector<Item>);
	Menu();
};