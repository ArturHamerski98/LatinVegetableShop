#include "ProductList.h"
class Cart {
public:
	std::list<Item> shoppingList;
	void addToCart(int ID, std::list<Item> myList);
	void deleteItemFromCart();
	void reviewCart();
};