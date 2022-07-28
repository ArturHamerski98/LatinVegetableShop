#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "CheckOutAndPayment.h"
#include "Menu.h"
#include <time.h>

int main() {
   
    Menu menu;
    std::cout << "Welcome in our shop. Choose option:\n";
    menu.superMenu();

    return 0;
}