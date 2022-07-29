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
		std::cout << " 4. Sorting products by name\n";
		std::cout << " 5. Sorting products by price\n";
		std::cout << " 6. Go to cart\n";
		std::cout << " 7. Order confirmation\n";
		std::cout << " 8. Admin panel\n";





		std::cout << "Your choice:";
		std::cin >> choice;


		while (true) {

			switch (choice) {

			case 1:
				productList.displayProducts();
				system("pause");
				break;

			case 2:
				askAfterFiltering(productList.filteringSuppliers());

				break;
			case 3:
				askAfterFiltering(productList.filteringCategory());
				break;

			case 4: //sortowanie
			case 5: //sortowanie 
			case 6:
				cart.userInteraction();
				break;
			case 7:
				
			case 8:
			case 9:
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
}

void Menu:: askAfterFiltering(std::vector<Item> Victorek) {

	bool temp1 = true;
	while (temp1)
	{
		std::cout << "What are you want to do now?\n";
		std::cout << "1. Add product to cart\n";
		std::cout << "2. Sorting products by name\n";
		std::cout << "3. Sorting products by price\n";
		std::cout << "4. Show details of products\n";
		std::cout << "5. Back to MENU\n";

		int choice{};
		std::cin >> choice;


		switch (choice) {

		case 1:
			int itemNumber;
			std::cout << "Choose product number:";
			std::cin >> itemNumber;
			cart.addToCart(Victorek[itemNumber]);
		case 2:
			productList.quickSortbyName(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++)
			{
				std::cout << i << "||" << Victorek[i].getName() << "||" << Victorek[i].getPrice() << "$" << std::endl;
			}
			break;
		case 3:
			productList.quickSortbyPrice(Victorek, 0, Victorek.size() - 1);
			for (int i = 0; i < Victorek.size(); i++)
			{
				std::cout << i << "||" << Victorek[i].getName() << "||" << Victorek[i].getPrice() << "$" << std::endl;
			}
			break;

		case 4:
			int itemNumber2;
			std::cout << "Choose product number:";
			std::cin >> itemNumber2;
			Victorek[itemNumber2].showDetails();
			system("pause");

		case 5:
			temp1 = false;
			break;
		}

	}
	
}