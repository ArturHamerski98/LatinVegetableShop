#pragma once
#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "User.h"

class Menu {
public:
	std::string log;
	ProductList productList;
	Cart cart;
	User user;
	bool isloged;
public:
	void superMenu();
	void askAfterFiltering(std::vector<Item*>);
	Menu();
};