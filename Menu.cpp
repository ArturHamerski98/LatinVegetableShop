#include "Menu.h"

void Menu::superMenu() {

	ProductList productList;

	int choice = 0;
	productList.readingDataFromCSVFile();



	std::cout << " 1. Review all products\n";
	std::cout << " 2. Filter by supplier\n";
	std::cout << " 3. Filter by category\n";
	std::cout << " 4. Sorting products by name\n";
	std::cout << " 5. Sorting products by price\n";
	std::cout << " 6. Show details of choosen product\n";
	std::cout << " 7. Go to payment\n";
	std::cout << " 8. Order confirmation\n";
	std::cout << " 9. Admin panel\n";

	std::cout << "Your choice:";
	std::cin >> choice;


	while (true) {
		
		switch (choice) {

		case 1:
			std::cout << "xsadfasdfas";
			productList.displayProducts();
			break;

		case 2:
			productList.filteringSuppliers();
			break;
		case 3:
			productList.filteringCategory();
			break;

		case 4: //sortowanie
		case 5: //sortowanie 
		case 6:
		case 7:
		case 8:
		case 9:
			break;
		}
		break;
	}
	
}