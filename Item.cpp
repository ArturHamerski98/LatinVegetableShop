#include "Item.h"
#include<iostream>


Item::Item(int ID, std::string name, std::string description, double price, bool availability, std::string supplier, std::string category){
    this->ID = ID;
    this->name = name;
    this->description = description;
    this->price = price;
    this->availability = availability;
    this->supplier = supplier;
    this->category = category;
    prodCart.name = name;
    prodCart.description = description;
    prodCart.price = price;
    prodCart.availability = availability;
    prodCart.supplier = supplier;
}
int Item::getID() {
    return ID;
}
std::string Item::getName() {
    return name;
}
std::string Item::getDescription() {
    return description;
}
double Item::getPrice() {
    return price;
}
bool Item::getAvailability() {
    return availability;
}
std::string Item::getSupplier() {
    return supplier;
}

std::string Item:: getCategory() {
   return category;
}

//int Item::ranndomCategory() {

  // srand(time(NULL));

  // return static_cast<int>(rand() % 2 + 0);
//}

void Item::showProductCart() {

    std::cout << name << std:: endl;
    std::cout << description << std::endl;
    std::cout << price << std::endl;
    std::cout << availability << std::endl;
    std::cout << supplier << std::endl;
    std::cout << category << std::endl;
}