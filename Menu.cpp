#include "Menu.h"

void Menu::superMenu() {

	ProductList productList;

	int choice = 0; 
	std::string choosenCountry{};
	productList.readingDataFromCSVFile();

	std::cout << "Welcome in our shop. Choose option: ";

	std::cout << " 1. Review all products\n";
	std::cout << " 2. Filter by supplier\n";
	std::cout << " 3. Filter by category\n";
	std::cout << " 4. Sorting products by name\n";
	std::cout << " 5. Sorting products by price\n";
	std::cout << " 6. Show details of choosen product\n";
	std::cout << " 7. Go to payment\n";
	std::cout << " 8. Order confirmation\n";
	std::cout << " 9. Admin panel\n";

	//swieze, 
	Item mis(12, "dsada", "sadas", 232, true, "Spain", "ds");
	choice = 1;
	switch (choice) {
	
	case 1:

		mis.showProductCart();
		productList.displayProducts();
		break;	
	case 2:
		productList.filteringSuppliers(choosenCountry);
		break;
	case 3:
		productList.filteringCategory(choosenCountry);
		break;
	case 4: //sortowanie
	case 5: //sortowanie 
	case 6:

	case 7:
	case 8:
	case 9:
	}
}