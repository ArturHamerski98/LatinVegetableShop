#include <iostream>
#include "Item.h"
#include "ProductList.h"
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>

int main() {
    ProductList productList;
    productList.readingDataFromCSVFile();
    productList.filteringSuppliers("Poland");
    productList.displayProducts();
    return 0;
}