#pragma once
#include<iostream>
#include<list>
class Item
{

    int ID;
    std::string name;
    std::string description;
    std::string category;
    double price;
    bool availability;
    std::string supplier;
    int quantity;
    struct productCart {
        std::string name;
        std::string description;
        double price;
        //bool availability;
        std::string supplier;
    };
    productCart prodCart;
public:
    Item(int ID, std::string name, std::string description, double price, bool availability, std::string supplier, std::string category, int quantity);
    int getID();
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    double getPrice();
    bool getAvailability();
    std::string getSupplier();
    void showDetails();
    void setQuantity(int value);
    int getQuantity();

};