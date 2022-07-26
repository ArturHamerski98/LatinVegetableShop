#include "ProductList.h"
#include <algorithm>

std::vector<Item> sortingByPrice(std::list<Item> myList2) {

std::vector <int> priceVector;
std::list<Item>::iterator price;

    for (price = myList.begin(); price != myList.end(); price++) {
    int id = price->getPrice();
    std::cout << id << std::endl;
    priceVector.push_back(id);
    }

    std::sort(priceVector.begin(), priceVector.end());
    return priceVector;
}
