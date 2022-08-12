#pragma once
#include "Item.h"
#include "ProductList.h"
#include "Cart.h"
#include "CheckOutAndPayment.h"
#include "Menu.h"
#include <time.h>
#include <iostream>
int main() {

    system("Color 30");
    Menu menu;


    std::cout << "|-------------------------|\n";
    std::cout << "|                         |\n";
    std::cout << "|      GROCERY SHOP       |\n";
    std::cout << "|                         |\n";
    std::cout << "|-------------------------|\n";

    std::cout << "Welcome in our shop. Choose option :\n";
    menu.superMenu();

    return 0;
}