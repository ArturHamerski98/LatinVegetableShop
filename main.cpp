#include <iostream>
#include "Item.h"
#include "Cart.h"
#include "ProductList.h"
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

int main() {
    ProductList productList;
    productList.readingDataFromCSVFile();
    Cart cart;
    cart.reviewCart();
    //cart.reviewCart();
    //std::cout<<productList.getItem(5).getName();
    return 0;
}