#pragma once
#include "Menu.h"


void Menu::superMenu() {

	
	int choice = 0;
	productList.readingDataFromCSVFile();
	int temp = 0;
	while (true)
	{
		
		if (temp != 0)
			system("cls");
		temp++;

		std::cout << "\n 1. Review all products\n";
		std::cout << " 2. Filter by supplier\n";
		std::cout << " 3. Filter by category\n";
		std::cout << " 4. Sorting all products by name A-Z\n";
		std::cout << " 5. Sorting all products by name Z-A\n";
		std::cout << " 6. Sorting all products by price (ascending order)\n";
		std::cout << " 7. Sorting products by price (descending order)\n";
		std::cout << " 8. Go to cart\n";
		std::cout << " 9. Order confirmation\n";
		std::cout << " 10. createAccount\n";
		std::cout << " 11. Log in\n";
		std::cout << " 12. Admin panel\n";
		std::cin >> choice;


		while (true) {

			switch (choice) {

			case 1:

				productList.displayProducts(productList.vectorofAll);
				askAfterFiltering(productList.vectorofAll);
				break;

			case 2:
				askAfterFiltering(productList.filteringSuppliers(productList.vectorofAll));

				break;
			case 3:
				askAfterFiltering(productList.filteringCategory(productList.vectorofAll));
				break;

			case 4: 
				
				productList.quickSortbyNameAscending(productList.vectorofAll,0, productList.vectorofAll.size() - 1);
				productList.displayProducts(productList.vectorofAll);
				askAfterFiltering(productList.vectorofAll);
				break;
			case 5: 
				productList.quickSortbyNameDescending(productList.vectorofAll, 0, productList.vectorofAll.size() - 1);
				productList.displayProducts(productList.vectorofAll);
				askAfterFiltering(productList.vectorofAll);
				break;
			case 6:
				productList.quickSortbyPriceAscending(productList.vectorofAll, 0, productList.vectorofAll.size() - 1);
				productList.displayProducts(productList.vectorofAll);
				askAfterFiltering(productList.vectorofAll);
				break;
			case 7:
				productList.quickSortbyPriceDescending(productList.vectorofAll, 0, productList.vectorofAll.size() - 1);
				productList.displayProducts(productList.vectorofAll);
				askAfterFiltering(productList.vectorofAll);
				break;
			case 8:
				cart.userInteraction();
				break;
			case 9:
				break;
			case 10:
				user.createAccount();
				break;
			case 11:
				user.LogIn();
				break;
			}
			break;
		}

	}
	

}

Menu::Menu()
{
	productList = ProductList();
	cart = Cart();
	user = User();
}

void Menu::askAfterFiltering(std::vector<Item*> Victorek) {

	bool temp1 = true;
	while (temp1)
	{
		std::cout << "What are you want to do now?\n";
		std::cout << "1. Add product to cart\n";
		std::cout << "2. Sorting products by name (A-Z)\n";
		std::cout << "3. Sorting products by name (Z-A)\n";
		std::cout << "4. Sorting products by price (ascending order) \n";
		std::cout << "5. Sorting products by price (descending order) \n";
		std::cout << "6. Show details of products\n";
		std::cout << "7. Back to MENU\n";

		int choice{};
		std::cin >> choice;
		std::string number{};


		switch (choice) {

		case 1:
			int itemNumber;
			std::cout << "Choose product number:";
			std::cin >> itemNumber;
			cart.addToCart(Victorek[itemNumber]);
			break;

		case 2:
			productList.quickSortbyNameAscending(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++) {
				std::cout << i << "||" << Victorek[i]->getName() << "||" << Victorek[i]->getPrice() << "$" << std::endl;
			}
			break;


		case 3:
			productList.quickSortbyNameDescending(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++) {
				std::cout << i << "||" << Victorek[i]->getName() << "||" << Victorek[i]->getPrice() << "$" << std::endl;
			}
			break;

		case 4:
			productList.quickSortbyPriceAscending(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++)
			{
				std::cout << i << "||" << Victorek[i]->getName() << "||" << Victorek[i]->getPrice() << "$" << std::endl;
			}
			break;

		case 5:
			productList.quickSortbyPriceDescending(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++)
			{
				std::cout << i << "||" << Victorek[i]->getName() << "||" << Victorek[i]->getPrice() << "$" << std::endl;
			}
			break;

		case 6:
			int itemNumber2;
			std::cout << "Choose product number:";
			std::cin >> itemNumber2;
			Victorek[itemNumber2]->showDetails();
			system("pause");
			break;

		case 7:
			temp1 = false;
			break;
		}
	}
}