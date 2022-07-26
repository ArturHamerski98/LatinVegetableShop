#include "Item.h"
//#include<iostream>

Item::Item(std::string supplier, std::string name, std::string description, int weight, double price) {
    this->supplier = supplier;
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->price = price;
    prodCart.description = description;
    prodCart.name = name;
    prodCart.price = price;
    prodCart.weight = weight;
}
int Item::getID() {
    return ID;
}
std::string Item::getSupplier() {
    return supplier;
}
std::string Item::getName() {
    return name;
}
std::string Item::getDescription() {
    return description;
}
int Item::getWeight() {
    return weight;
}
double Item::getPrice() {
    return price;
}