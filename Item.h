#pragma once
#include<iostream>
#include<list>
#include <vector>

class Item
{
    int ID;
    std::string name; 
    std::string description;
    std::string category;
    double price;
    bool availability;
    std::string supplier;
    std::string category;
    
    struct productCart {
        std::string name;
        std::string description;
        double price;
        bool availability;
        std::string supplier;
        std::string category;
       
    };
public:
    //std::vector<std::string> vectorCategory{ "fresh", "short expiry date", "at your own risk" };
    productCart prodCart;
public:
    Item(int ID, std::string name, std::string description, double price, bool availability, std::string supplier, std::string category);
    int getID();
    std::string getName();
    std::string getDescription();
    std::string getCategory();
    double getPrice();
    bool getAvailability();
    std::string getSupplier();
    std::string getCategory();
    int ranndomCategory();
    void showProductCart();
};