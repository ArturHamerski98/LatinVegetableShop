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
    return 0;
}