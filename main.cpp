#include <iostream>
#include "Item.h"
#include<list>
int main() {
    std::list<Item> myList;
    Item lodowka("Media Expert", "Lodowka1", "Super lodowka", 50, 1000.00);
    Item odkurzacz("Media Expert", "Lodowka2", "Super lodowka", 50, 1000.00);
    Item Suszarka("Media Expert", "Lodowka3", "Super lodowka", 50, 1000.00);
    Item TV("Media Expert", "Lodowka4", "Super lodowka", 50, 1000.00);
    myList.push_back(lodowka);
    myList.push_back(odkurzacz);
    myList.push_back(Suszarka);
    myList.push_back(TV);
    std::list<Item>::iterator it;
    for (it = myList.begin(); it != myList.end(); it++)
    {
        // Access the object through iterator
        int id = it->getPrice();
       
        std::cout << id << std::endl;
    }
    return 0;
}