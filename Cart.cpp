#pragma once
#include "Cart.h"
#include <string>
void Cart::addToCart(Item *addedItem) {
	if (addedItem->getQuantity() < 1) {
		std::cout << "Unfortunately we have run out of this product. Try to choose something else\n";
		system("pause");
		return;
	}
	shoppingList.push_back({ addedItem, 1 });
	addedItem->setQuantity(addedItem->getQuantity() - 1);
	adminLog += getTime();
	adminLog += " ";
	adminLog += "anonymous person ";
	adminLog += "added ";
	adminLog += addedItem->getName();
	adminLog += "\n";
}

void Cart::reviewCart() {
	int position = 0;
	for (auto item =shoppingList.begin(); item != shoppingList.end(); item++) {
		std::cout << position << ": " << ProductList::proText(item->item->getSupplier(), 14) << "||" << ProductList::proText(item->item->getName(), 34) << "||" << ProductList::proText(std::to_string(item->item->getPrice()), 14) << "||" << item->quantity << "\n";
		position++;
		totalPrice += item->item->getPrice()*item->quantity;
	}
	std::cout <<"Total price: "<< totalPrice;
}

void Cart::deleteItemFromCart(int position) {
	
	int temp = 0;
	for (auto itr = shoppingList.begin(); itr != shoppingList.end(); itr++,temp++)
	{
		if (temp == position)
		{
			adminLog += getTime();
			adminLog += " ";
			adminLog += "anonymous person ";
			adminLog += "deleted ";
			adminLog += itr->item->getName();
			adminLog += "\n";

			itr->item->setQuantity(itr->item->getQuantity()+itr->quantity);
			shoppingList.erase(itr);
			break;
		}
	}
	
}
void Cart::changeQuantity(int position, int quantity) {
	int temp = 0;
	for (auto itr = shoppingList.begin(); itr != shoppingList.end(); itr++, temp++) {

		if (temp == position) {
			
				if (itr->item->getQuantity()+itr->quantity < quantity) {
					std::cout << "Improper quantity!\n";
					system("pause");
					return;
				}
				adminLog += getTime();
				adminLog += " ";
				adminLog += "anonymous person ";
				adminLog += "changed quantity of  ";
				adminLog += itr->item->getName();
				adminLog += "\n";

			itr->item->setQuantity((itr->item->getQuantity() - quantity + itr->quantity));
			itr->quantity = quantity;
			
			break;
		}
	}
}

void Cart::userInteraction() {
	bool temp = true;
	CheckOutAndPayment myCOAP;
	std::string boughtItems="";
	while (temp)
	{
		reviewCart();
		std::cout << "\nHello! Press a digit corresponding to the action you want to take:\n";
		std::cout << "1: Back to shoping\n";
		std::cout << "2: delete an element from you shopping list\n";
		std::cout << "3: go to confirmation\n";
		std::cout << "4: change the quantity of one of the products\n";
		int choice;
		std::cin >> choice;
		int position;
		
		switch (choice) {
		case 1:
			temp = false;
			break;

		case 2:
			std::cout << "Enter the position of the product you want to delete:\n";
			std::cin >> position;
			deleteItemFromCart(position);
			break;
		case 3:
			for (auto item = shoppingList.begin(); item != shoppingList.end(); item++) {
				boughtItems+= std::to_string(item->item->getID());
				boughtItems += ",";
			}
			myCOAP.setTotalPrice(totalPrice);
			myCOAP.setBoughtItems(boughtItems);
			myCOAP.checkOut();
			
			break;
		case 4:
			std::cout << "Enter the position of the product:";
			std::cin >> position;
			std::cout << "Specify the quantity:";
			int quantity;
			std::cin >> quantity;
			changeQuantity(position, quantity);
			break;
		}




	}
	
}
std::string Cart::getTime(){
	time_t now = time(0);
	tm* ltm = localtime(&now);

	std::string dateString = "", tmp = "";
	tmp = std::to_string(ltm->tm_mday);
	if (tmp.length() == 1)
		tmp.insert(0, "0");
	dateString += tmp;
	dateString += "-";
	tmp = std::to_string(1 + ltm->tm_mon);
	if (tmp.length() == 1)
		tmp.insert(0, "0");
	dateString += tmp;
	dateString += "-";
	tmp = std::to_string(1900 + ltm->tm_year);
	dateString += tmp;
	dateString += " ";
	tmp = std::to_string(ltm->tm_hour);
	if (tmp.length() == 1)
		tmp.insert(0, "0");
	dateString += tmp;
	dateString += ":";
	tmp = std::to_string(1 + ltm->tm_min);
	if (tmp.length() == 1)
		tmp.insert(0, "0");
	dateString += tmp;
	dateString += ":";
	tmp = std::to_string(1 + ltm->tm_sec);
	if (tmp.length() == 1)
		tmp.insert(0, "0");
	dateString += tmp;

	return dateString;
}
void Cart::adminLogToTXT() {
	std::ofstream myfile;
	myfile.open("adminLog.txt");
	myfile << adminLog;
	myfile.close();
}