#include "ProductList.h"


std::vector<int> ProductList::sortingByPrice(std::list<Item> myList2) {

    std::vector <int> priceVector;
    std::list<Item>::iterator price;

    for (price = myList2.begin(); price != myList2.end(); price++) {
    int id = price->getPrice();
   
    priceVector.push_back(id);
    }

    std::sort(priceVector.begin(), priceVector.end());
    return priceVector;
}


std::vector<std::string>ProductList::filteringSuppliers(std::list<Item> myList2) {

    std::vector <std::string> supplierVector;
    std::list<Item>::iterator supplier;

    for (auto supplier = myList2.begin(); supplier != myList2.end(); supplier++) {
        std::string id = supplier->getSupplier();

        supplierVector.push_back(id);
    }
    return supplierVector;
}

/*std::vector<Item> filteringCategory(std::list<Item> myList2) {

    std::vector <std::string> categoryVector;
    std::list<Item>::iterator category;

    for (auto supplier = myList2.begin(); category != myList2.end(); supplier++) {
        std::string id = supplier->getSupplier();

        categoryVector.push_back(id);
    }
    return categoryVector;

}
*/

void displayProducts(std::list<Item>myList2) {

    std::list<Item>::iterator name;
   

    for (auto name = myList2.begin(); name != myList2.end(); name++) {
        std::string id = name->getName();
        std::cout << id << std::endl;
    }
}