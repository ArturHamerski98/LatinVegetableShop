#pragma once
#include "ProductList.h"
#include "CheckOutAndPayment.h"
struct product {
	Item item;
	int quantity;
};
class Cart {
public:
	double totalPrice;
	std::list <product> shoppingList;
	void addToCart(Item newItem);
	void deleteItemFromCart(int position);
	void reviewCart();
	void setQuantity(int position, int quantity);
	void userInteraction();
	
};