#include "Cart.h"
void Cart::addToCart(int ID, std::list<Item> myList) {
	std::list<Item>::iterator itr = myList.begin();
	for (int i = 0; i < ID; i++) {
		itr++;
	}
	shoppingList.push_back(*itr);
}
void Cart::deleteItemFromCart(int ID) {
	std::list<Item>::iterator itr = shoppingList.begin();
	for (int i = 0; i < ID; i++) {
		itr++;
	}
	shoppingList.erase(*itr);
}
void Cart::reviewCart() {
	std::list<Item>::iterator itr;
	for (itr = shoppingList.begin(); itr != shoppingList.end(); itr++) {
		std::cout << itr.getName() << std::endl;
		std::cout << itr.getDescription() << std::endl;
		std::cout << itr.getPrice() << std::endl;
		std::cout << itr.getAvailability() << std::endl;
		std::cout << itr.getSupplier() << std::endl;
		std::cout << "---------------------------------------------------------------------";
	}
}
