#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "ProductList.h"
#include "CheckOutAndPayment.h"
struct product {
	Item *item;
	int quantity;
};
class Cart {
public:
	std::string adminLog;
	double totalPrice;
	std::list <product> shoppingList;
	std::string getTime();
	void addToCart(Item *newItem);
	void deleteItemFromCart(int position);
	void reviewCart();
	void changeQuantity(int position, int quantity);
	void userInteraction();
	void adminLogToTXT();
};