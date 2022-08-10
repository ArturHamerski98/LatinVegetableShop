#pragma once
#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "CheckOutAndPayment.h"

class Menu {
public:
	ProductList productList;
	Cart cart;
	CheckOutAndPayment checkOutAndPayment;
public:
	void superMenu();
	void askAfterFiltering(std::vector<Item>);
	Menu();
};