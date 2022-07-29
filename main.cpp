#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "CheckOutAndPayment.h"
#include "Menu.h"
#include <time.h>

int main() {

    ProductList productList;
    productList.readingDataFromCSVFile();
    productList.filteringSuppliers("Poland");

    return 0;
}