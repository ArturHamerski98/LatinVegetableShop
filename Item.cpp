#pragma once
#include "Item.h"

Item::Item(int ID, std::string name, std::string description, double price, bool availability, std::string supplier, std::string category) {
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
std::string Item::getCategory()
{
    return category;
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

