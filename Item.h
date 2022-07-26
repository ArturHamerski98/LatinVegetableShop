#pragma once
#include<iostream>
#include<list>
class Item
{
    int ID;
    std::string name; 
    std::string description;
    double price;
    bool availability;
    std::string supplier;
    struct productCart {
        std::string name;
        std::string description;
        double price;
        bool availability;
        std::string supplier;
    };
    productCart prodCart;
public:
    Item(int ID, std::string name, std::string description, double price, bool availability, std::string supplier);
    int getID();
    std::string getName();
    std::string getDescription();
    double getPrice();
    bool getAvailability();
    std::string getSupplier();
};