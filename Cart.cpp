#include "Cart.h"
void Cart::addToCart(Item addedItem) {
	shoppingList.push_back({ addedItem, 3 });
}

void Cart::reviewCart() {
	int position = 0;
	for (auto item =shoppingList.begin(); item != shoppingList.end(); item++) {
			std::cout <<position<<": " << item->item.getSupplier() << "||" << item->item.getName() << "||" << item->item.getPrice() << "||"<<item->quantity << "\n";
			position++;
			totalPrice += item->item.getPrice()*item->quantity;
	}
	std::cout << totalPrice;
}

void Cart::deleteItemFromCart(int position) {
	
	int temp = 0;
	for (auto item = shoppingList.begin(); item != shoppingList.end(); item++,temp++)
	{
		if (temp == position)
		{
			shoppingList.erase(item);
			break;
		}
	}
	
}
void Cart::setQuantity(int position, int quantity) {
	int temp = 0;
	for (auto item = shoppingList.begin(); item != shoppingList.end(); item++, temp++) {
		if (temp == position) {
			item->quantity = quantity;
			break;
		}
	}
}
void Cart::userInteraction() {
	reviewCart();
	std::cout << "Hello! Press a digit corresponding to the action you want to take:\n";
	std::cout << "1: add new element to your shopping list\n";
	std::cout << "2: delete an element from you shopping list\n";
	std::cout << "3: review the whole shopping list\n";
	std::cout << "4: change the quantity of one of the products\n";
	int choice;
	std::cin >> choice;
	int position;
	CheckOutAndPayment myCOAP(totalPrice);
	switch (choice) {
	case 1:
		std::cout << "back to menu";
		//artur ufam Tobie 
		break;

	case 2:
		std::cout << "Enter the position of the product you want to delete:\n";
		std::cin >> position;
		deleteItemFromCart(position);
		break;
	case 3:
		std::cout << "Enter the position of the product you want to display info:\n";
		
		myCOAP.checkOut();
		
		break;
	case 4:
		std::cout << "Enter the position of the product:";
		
		std::cin >> position;
		std::cout << "Specify the quantity:";
		int quantity;
		std::cin >> quantity;
		setQuantity(position, quantity);
		break;
	}
}
void Cart::saveData() {
	std::ofstream outputFile("outputFile.csv");
	std::list<product>::iterator itr;
	for (itr = shoppingList.begin(); itr != shoppingList.end(); itr++) {
		outputFile << itr->item.getID(); outputFile << "\n";
		outputFile << itr->item.getName(); outputFile << "\n";
		outputFile << itr->item.getDescription(); outputFile << "\n";
		outputFile << itr->item.getPrice(); outputFile << "\n";
		outputFile << itr->item.getAvailability(); outputFile << "\n";
		outputFile << itr->item.getSupplier(); outputFile << "\n";
		outputFile << itr->item.getCategory(); outputFile << "\n";
	}
	outputFile.close();
}